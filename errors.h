#pragma once

/**
 * @file errors.h
 * @brief Заголовочный файл с определениями классов исключений.
 */

#include <stdexcept>
#include <string>

/**
 * @brief Класс критических ошибок.
 * @details Выбрасывается при возникновении ошибок, которые требуют немедленного
 * завершения работы программы
 */
class CritErr : public std::runtime_error {
public:
    /**
     * @brief Конструктор критической ошибки.
     * @param msg Текст сообщения об ошибке.
     */
    explicit CritErr(const std::string& msg) : std::runtime_error(msg) {}
};

/**
 * @brief Класс некритических ошибок.
 * @details Выбрасывается при ошибках, связанных с конкретным клиентом (например, неверный пароль).
 * Сервер продолжает работу после перехвата этого исключения.
 */
class NoCritErr : public std::runtime_error {
public:
    /**
     * @brief Конструктор некритической ошибки.
     * @param msg Текст сообщения об ошибке.
     */
    explicit NoCritErr(const std::string& msg) : std::runtime_error(msg) {}
};
