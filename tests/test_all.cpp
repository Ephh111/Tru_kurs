#include <UnitTest++/UnitTest++.h>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include "interface.h"
#include "logger.h"
#include "base.h"
#include "calc.h"
#include "communicator.h"
#include "errors.h"

SUITE(InterfaceTest) {
    TEST(HelpRequest) {
        Interface iface;
        char arg0[] = "test";
        char arg1[] = "-h";
        char* argv[] = {arg0, arg1, nullptr};
        ConfigParams params = iface.parse_cmd(2, argv);
        CHECK(params.help_requested);
    }

    TEST(DefaultValues) {
        Interface iface;
        char arg0[] = "test";
        char* argv[] = {arg0, nullptr};
        ConfigParams params = iface.parse_cmd(1, argv);
        CHECK(params.help_requested);
    }

    TEST(CustomPort) {
        Interface iface;
        char arg0[] = "test";
        char arg1[] = "-p";
        char arg2[] = "8080";
        char* argv[] = {arg0, arg1, arg2, nullptr};
        ConfigParams params = iface.parse_cmd(3, argv);
        CHECK_EQUAL(8080, params.port);
    }

    TEST(CustomFiles) {
        Interface iface;
        char arg0[] = "test";
        char arg1[] = "-f";
        char arg2[] = "my_base.txt";
        char arg3[] = "-l";
        char arg4[] = "my_log.txt";
        char* argv[] = {arg0, arg1, arg2, arg3, arg4, nullptr};
        ConfigParams params = iface.parse_cmd(5, argv);
        CHECK_EQUAL("my_base.txt", params.base_file);
        CHECK_EQUAL("my_log.txt", params.log_file);
    }

    TEST(InvalidPortException) {
        Interface iface;
        char arg0[] = "test";
        char arg1[] = "-p";
        char arg2[] = "999999";
        char* argv[] = {arg0, arg1, arg2, nullptr};
        CHECK_THROW(iface.parse_cmd(3, argv), std::invalid_argument);
    }

    TEST(UnknownOptionException) {
        Interface iface;
        char arg0[] = "test";
        char arg1[] = "-z";
        char* argv[] = {arg0, arg1, nullptr};
        CHECK_THROW(iface.parse_cmd(2, argv), std::invalid_argument);
    }
}


SUITE(LoggerTest) {
    struct LogFixture {
        std::string filename = "test_log.txt";
        LogFixture() { std::remove(filename.c_str()); }
        ~LogFixture() { std::remove(filename.c_str()); }
    };

    TEST_FIXTURE(LogFixture, WriteWarning) {
        Logger log(filename);
        log.log("Test message", false);
        
        std::ifstream f(filename);
        std::string content((std::istreambuf_iterator<char>(f)),
                             std::istreambuf_iterator<char>());
        CHECK(content.find("[WARNING] Test message") != std::string::npos);
    }

    TEST_FIXTURE(LogFixture, WriteCritical) {
        Logger log(filename);
        log.log("Critical error", true);
        
        std::ifstream f(filename);
        std::string content((std::istreambuf_iterator<char>(f)),
                             std::istreambuf_iterator<char>());
        CHECK(content.find("[CRITICAL] Critical error") != std::string::npos);
    }
}


SUITE(BaseTest) {
    struct BaseFixture {
        std::string filename = "test_base.txt";
        BaseFixture() {
            std::ofstream f(filename);
            f << "user1:pass1\nuser2:pass2\n";
        }
        ~BaseFixture() { std::remove(filename.c_str()); }
    };

    TEST_FIXTURE(BaseFixture, LoadAndGet) {
        Base db;
        db.load_base(filename);
        CHECK_EQUAL("pass1", db.get_password("user1"));
        CHECK_EQUAL("pass2", db.get_password("user2"));
    }

    TEST_FIXTURE(BaseFixture, UserNotFound) {
        Base db;
        db.load_base(filename);
        CHECK_THROW(db.get_password("unknown"), NoCritErr);
    }

    TEST(FileNotFound) {
        Base db;
        CHECK_THROW(db.load_base("nonexistent_file.txt"), CritErr);
    }
}


SUITE(CalcTest) {
    TEST(AverageSimple) {
        std::vector<int16_t> v = {10, 20, 30};
        CHECK_EQUAL(20, Calc::compute_average(v));
    }

    TEST(ExtremeValues) {
        std::vector<int16_t> v_max = {32767, 32767};
        CHECK_EQUAL(32767, Calc::compute_average(v_max));

        std::vector<int16_t> v_min = {-32768, -32768};
        CHECK_EQUAL(-32768, Calc::compute_average(v_min));
    }

    TEST(EmptyVector) {
        std::vector<int16_t> v;
        CHECK_EQUAL(0, Calc::compute_average(v));
    }

    TEST(NegativeAverage) {
        std::vector<int16_t> v = {-10, -20, -30};
        CHECK_EQUAL(-20, Calc::compute_average(v));
    }
}


SUITE(CommunicatorTest) {
    TEST(Sha1Calculation) {
        Base base;
        Logger logger("dum.log");
        Communicator comm(33333, base, logger);
    }
}

int main() {
    return UnitTest::RunAllTests();
}
