#include "interface.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

ConfigParams Interface::parse_cmd(int argc, char** argv) {
    ConfigParams params;

    if (argc == 1) {
        params.help_requested = true;
        return params;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            params.help_requested = true;
            return params;
        } 
        else if (arg == "-f" || arg == "--file") {
            if (i + 1 < argc) {
                params.base_file = argv[++i];
            } else {
                throw std::invalid_argument("Ошибка: не указано значение для параметра -f/--file");
            }
        } 
        else if (arg == "-l" || arg == "--log") {
            if (i + 1 < argc) {
                params.log_file = argv[++i];
            } else {
                throw std::invalid_argument("Ошибка: не указано значение для параметра -l/--log");
            }
        } 
        else if (arg == "-p" || arg == "--port") {
            if (i + 1 < argc) {
                try {
                    int port_val = std::stoi(argv[++i]);
                    if (port_val < 0 || port_val > 65535) {
                        throw std::out_of_range("Порт должен быть в диапазоне от 0 до 65535");
                    }
                    params.port = static_cast<uint16_t>(port_val);
                } catch (const std::exception&) {
                    throw std::invalid_argument("Ошибка: неверное значение порта");
                }
            } else {
                throw std::invalid_argument("Ошибка: не указано значение для параметра -p/--port");
            }
        } 
        else {
            throw std::invalid_argument("Ошибка: неизвестный параметр " + arg);
        }
    }

    return params;
}

void Interface::print_help() const {
    std::cout << "Программа сетевого сервера обработки векторов\n";
    std::cout << "Допустимые параметры:\n";
    std::cout << "  -h, --help          Выдать справку\n";
    std::cout << "  -f, --file <path>   Путь к базе клиентов (по умолчанию: /etc/vcalc.conf)\n";
    std::cout << "  -l, --log <path>    Путь к файлу журнала (по умолчанию: /var/log/vcalc.log)\n";
    std::cout << "  -p, --port <num>    Порт сервера (по умолчанию: 33333)\n";
}
