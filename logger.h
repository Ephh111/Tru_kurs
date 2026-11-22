#pragma once

/**
 * @file logger.h
 * @brief Заголовочный файл для логирования
 */

#include <string>
#include <fstream>

/**
 * @brief Класс для записи логов в файл.
 */
class Logger {
private:
    /** @brief Путь к файлу журнала. */
    std::string log_file_path;

public:
    /**
     * @brief Конструктор логгера.
     * @param path Путь к файлу лога. По умолчанию "/var/log/vcalc.log".
     */
    explicit Logger(const std::string& path = "/var/log/vcalc.log");
    
    /**
     * @brief Записывает сообщение в лог.
     * @param message Текст сообщения.
     * @param is_critical Флаг критичности (true - CRITICAL, false - WARNING).
     * @throw CritErr Если файл лога не может быть открыт.
     */
    void log(const std::string& message, bool is_critical);
};
