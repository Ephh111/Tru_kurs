#pragma once
#include <string>
#include <unordered_map>

class Base {
private:
    std::unordered_map<std::string, std::string> users;

public:
    Base() = default;
    void load_base(const std::string& file_path);
    std::string get_password(const std::string& login) const;
};