#pragma once
#include <stdexcept>
#include <string>

class CritErr : public std::runtime_error {
public:
    explicit CritErr(const std::string& msg) : std::runtime_error(msg) {}
};

class NoCritErr : public std::runtime_error {
public:
    explicit NoCritErr(const std::string& msg) : std::runtime_error(msg) {}
};
