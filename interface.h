#pragma once

/**
 * @file interface.h
 * @brief Заголовочный файл интерфейса командной строки.
 */

#include <string>
#include <cstdint>

/**
 * @brief Структура параметров конфигурации.
 */
struct ConfigParams {
    std::string base_file = "/etc/vcalc.conf"; ///< Путь к БД
    std::string log_file = "/var/log/vcalc.log"; ///< Путь к файлу лога
    uint16_t port = 33333; ///< Порт сервера
    bool help_requested = false; ///< Флаг запроса справки
};

/**
 * @brief Класс для разбора аргументов командной строки.
 */
class Interface {
public:
    /** @brief Конструктор по умолчанию. */
    Interface() = default;
    
    /**
     * @brief Разбирает аргументы командной строки.
     * @param argc Количество аргументов.
     * @param argv Массив строковых аргументов.
     * @return Структура с параметрами конфигурации.
     * @throw std::invalid_argument При неверных аргументах.
     */
    ConfigParams parse_cmd(int argc, char** argv);
    
    /**
     * @brief Выводит справку
     */
    void print_help() const;
};
