#pragma once
#include <string>
#include <boost/program_options.hpp>

struct ConfigParams {
    std::string base_file = "/etc/vcalc.conf";
    std::string log_file = "/var/log/vcalc.log";
    uint16_t port = 33333;
    bool help_requested = false;
};

class Interface {
private:
    boost::program_options::options_description desc;

public:
    Interface();
    ConfigParams parse_cmd(int argc, char** argv);
    void print_help() const;
};