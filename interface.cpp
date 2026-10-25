#include "interface.h"
#include <iostream>

namespace po = boost::program_options;

Interface::Interface() : desc("Допустимые параметры") {
    desc.add_options()
        ("help,h", "Выдать справку")
        ("file,f", po::value<std::string>()->default_value("/etc/vcalc.conf"), "Путь к базе клиентов")
        ("log,l", po::value<std::string>()->default_value("/var/log/vcalc.log"), "Путь к файлу журнала")
        ("port,p", po::value<uint16_t>()->default_value(33333), "Порт сервера");
}

ConfigParams Interface::parse_cmd(int argc, char** argv) {
    ConfigParams params;
    po::variables_map vm;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help") || argc == 1) {
        params.help_requested = true;
        return params;
    }

    params.base_file = vm["file"].as<std::string>();
    params.log_file = vm["log"].as<std::string>();
    params.port = vm["port"].as<uint16_t>();

    return params;
}

void Interface::print_help() const {
    std::cout << "Программа сетевого сервера обработки векторов\n";
    std::cout << desc << std::endl;
}