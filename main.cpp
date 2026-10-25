#include "interface.h"
#include "base.h"
#include "logger.h"
#include "communicator.h"
#include "errors.h"
#include <iostream>

int main(int argc, char** argv) {
    try {
        Interface iface;
        ConfigParams config = iface.parse_cmd(argc, argv);

        if (config.help_requested) {
            iface.print_help();
            return 0;
        }

        Logger logger(config.log_file);
        Base base;

        base.load_base(config.base_file);

        Communicator communicator(config.port, base, logger);
        communicator.start();

    } catch (const CritErr& e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка выполнения: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}