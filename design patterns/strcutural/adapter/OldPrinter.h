// OldPrinter.h
#pragma once
#include <iostream>

class OldPrinter {
public:
    void printOld(const std::string& text) {
        std::cout << "Old Printer: " << text << std::endl;
    }
};
