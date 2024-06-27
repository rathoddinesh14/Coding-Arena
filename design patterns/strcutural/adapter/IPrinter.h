// IPrinter.h
#pragma once

#include <string>

class IPrinter {
public:
    virtual ~IPrinter() {}
    virtual void print(const std::string& text) = 0;
};
