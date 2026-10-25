#include "communicator.h"
#include "calc.h"
#include "errors.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

Communicator::Communicator(uint16_t port, Base& base, Logger& logger)
    : server_socket(-1), port(port), base(base), logger(logger) {}

Communicator::~Communicator() {
    if (server_socket != -1) {
        close(server_socket);
    }
}

std::string Communicator::calculate_sha1(const std::string& input) {
    CryptoPP::SHA1 sha1;
    std::string hash_16;
    CryptoPP::StringSource ss(
        input, true,
        new CryptoPP::HashFilter(
            sha1,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(hash_16), true
            )
        )
    );
    return hash_16;
}

void Communicator::start() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        throw CritErr("Failed to create socket");
    }

    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        throw CritErr("Bind failed on port " + std::to_string(port));
    }

    if (listen(server_socket, 5) < 0) {
        throw CritErr("Listen failed");
    }

    while (true) {
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);

        if (client_socket < 0) {
            logger.log("Failed to accept client connection", false);
            continue;
        }

        try {
            handle_client(client_socket);
        } catch (const NoCritErr& e) {
            logger.log(e.what(), false);
        } catch (const std::exception& e) {
            logger.log(std::string("Client processing error: ") + e.what(), false);
        }

        close(client_socket);
    }
}

void Communicator::handle_client(int client_socket) {
    char buf[1024];
    ssize_t bytes_read = recv(client_socket, buf, sizeof(buf) - 1, 0);
    if (bytes_read <= 56) {
        send(client_socket, "ERR", 3, 0);
        throw NoCritErr("Invalid authentication message format");
    }
    buf[bytes_read] = '\0';
    std::string msg(buf, bytes_read);

    while (!msg.empty() && (msg.back() == '\n' || msg.back() == '\r')) {
        msg.pop_back();
    }

    if (msg.length() <= 56) {
        send(client_socket, "ERR", 3, 0);
        throw NoCritErr("Invalid authentication message format after trim");
    }

    std::string received_hash = msg.substr(msg.length() - 40);
    std::string salt = msg.substr(msg.length() - 56, 16);
    std::string login = msg.substr(0, msg.length() - 56);

    std::string password;
    try {
        password = base.get_password(login);
        if (!password.empty() && password.back() == '\r') {
            password.pop_back();
        }
    } catch (const NoCritErr& e) {
        send(client_socket, "ERR", 3, 0);
        throw;
    }

    //хэш
    std::string expected_hash = calculate_sha1(salt + password);

    std::string received_hash_upper = received_hash;
    for (char& c : received_hash_upper) c = std::toupper(c);

    std::string expected_hash_upper = expected_hash;
    for (char& c : expected_hash_upper) c = std::toupper(c);

    if (received_hash_upper != expected_hash_upper) {
        send(client_socket, "ERR", 3, 0);
        throw NoCritErr("Authentication failed for user: " + login);
    }

    //Успешная аутентификация
    send(client_socket, "OK", 2, 0);

    //Двоичный обмен данными
    uint32_t num_vectors = 0;
    if (recv(client_socket, &num_vectors, sizeof(num_vectors), MSG_WAITALL) <= 0) {
        throw NoCritErr("Failed to receive number of vectors");
    }
    
    for (uint32_t i = 0; i < num_vectors; ++i) {
        uint32_t vector_size = 0;
        if (recv(client_socket, &vector_size, sizeof(vector_size), MSG_WAITALL) <= 0) {
            throw NoCritErr("Failed to receive vector size");
        }

        std::vector<int16_t> vector_data(vector_size);
        if (recv(client_socket, vector_data.data(), vector_size * sizeof(int16_t), MSG_WAITALL) <= 0) {
            throw NoCritErr("Failed to receive vector elements");
        }

        int16_t avg = Calc::compute_average(vector_data);
        
        send(client_socket, &avg, sizeof(avg), 0);
    }
}