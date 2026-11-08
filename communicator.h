#pragma once
#include "base.h"
#include "logger.h"
#include <cstdint>

class Communicator {
private:
    int server_socket;
    uint16_t port;
    Base& base;
    Logger& logger;

    std::string calculate_sha1(const std::string& input);
    void handle_client(int client_socket);
    
    friend struct CommunicatorTest_Sha1Calculation_Test;

public:
    Communicator(uint16_t port, Base& base, Logger& logger);
    ~Communicator();
    void start();
};
