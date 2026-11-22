#pragma once

/**
 * @file communicator.h
 * @brief Заголовочный файл сетевого взаимодействия.
 */

#include "base.h"
#include "logger.h"
#include <cstdint>

/**
 * @brief Класс сетевого сервера.
 * @details Обрабатывает подключения, аутентификацию и вычисления.
 */
class Communicator {
private:
    int server_socket; ///< Дескриптор серверного сокета
    uint16_t port; ///< Порт
    Base& base; ///< Ссылка на БД
    Logger& logger; ///< Ссылка на логгер

    /**
     * @brief Вычисляет SHA-1 хеш строки в hex-формате.
     * @param input Входная строка.
     * @return Строка с 40-символьным hex-хешем.
     */
    std::string calculate_sha1(const std::string& input);
    
    /**
     * @brief Обрабатывает подключение одного клиента.
     * @param client_socket Дескриптор клиентского сокета.
     * @throw NoCritErr При некритических ошибках
     */
    void handle_client(int client_socket);
    
    friend struct CommunicatorTest_Sha1Calculation_Test;

public:
    /**
     * @brief Конструктор коммуникатора.
     * @param port Порт для прослушивания.
     * @param base Ссылка на БД.
     * @param logger Ссылка на логгер.
     */
    Communicator(uint16_t port, Base& base, Logger& logger);
    
    /** @brief Деструктор, закрывает сокет. */
    ~Communicator();
    
    /**
     * @brief Запускает сервер и входит в бесконечный цикл приема подключений.
     * @throw CritErr Если не удается создать сокет или привязать его к порту.
     */
    void start();
};
