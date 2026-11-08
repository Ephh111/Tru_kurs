#pragma once
#include <string>
#include <cstdint>

struct ConfigParams {
    std::string base_file = "/etc/vcalc.conf";
    std::string log_file = "/var/log/vcalc.log";
    uint16_t port = 33333;
    bool help_requested = false;
};

class Interface {
public:
    Interface() = default;
    ConfigParams parse_cmd(int argc, char** argv);
    void print_help() const;
};
