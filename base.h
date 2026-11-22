#pragma once

/**
 * @file base.h
 * @brief Заголовочный файл для работы с базой данных пользователей.
 */

#include <string>
#include <unordered_map>

/**
 * @brief Класс для хранения и загрузки базы пользователей.
 */
class Base {
private:
    /** @brief Ассоциативный массив, хранящий пары логин-пароль. */
    std::unordered_map<std::string, std::string> users;

public:
    /** @brief Конструктор по умолчанию. */
    Base() = default;
    
    /**
     * @brief Загружает базу пользователей из файла.
     * @param file_path - Путь к файлу базы данных.
     * @throw CritErr Если файл не может быть открыт.
     */
    void load_base(const std::string& file_path);
    
    /**
     * @brief Возвращает пароль по логину.
     * @param login - Логин пользователя.
     * @return Строка с паролем.
     * @throw NoCritErr Если пользователь не найден.
     */
    std::string get_password(const std::string& login) const;
};
