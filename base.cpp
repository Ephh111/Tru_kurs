#include "base.h"
#include "errors.h"
#include <fstream>
#include <sstream>

void Base::load_base(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw CritErr("Failed to open user database file: " + file_path);
    }

    users.clear();
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string login = line.substr(0, pos);
            std::string password = line.substr(pos + 1);
            users[login] = password;
        }
    }
}

std::string Base::get_password(const std::string& login) const {
    auto it = users.find(login);
    if (it != users.end()) {
        return it->second;
    }
    throw NoCritErr("User not found: " + login);
}