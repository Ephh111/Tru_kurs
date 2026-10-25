#pragma once
#include <string>
#include <fstream>
#include <mutex>

class Logger {
private:
    std::string log_file_path;
    std::mutex log_mutex;

public:
    explicit Logger(const std::string& path = "/var/log/vcalc.log");
    void log(const std::string& message, bool is_critical);
};