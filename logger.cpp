#include "logger.h"
#include "errors.h"
#include <chrono>
#include <iomanip>
#include <sstream>

Logger::Logger(const std::string& path) : log_file_path(path) {}

void Logger::log(const std::string& message, bool is_critical) {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::ofstream file(log_file_path, std::ios::app);
    if (!file.is_open()) {
        throw CritErr("Failed to open log file: " + log_file_path);
    }

    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&time_t_now), "%Y-%m-%d %H:%M:%S");

    file << "[" << ss.str() << "] "
         << (is_critical ? "[CRITICAL] " : "[WARNING] ")
         << message << std::endl;
}