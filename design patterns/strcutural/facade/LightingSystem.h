// LightingSystem.h
#pragma once
#include <iostream>

class LightingSystem {
public:
    void on() {
        std::cout << "Lighting system is on." << std::endl;
    }

    void off() {
        std::cout << "Lighting system is off." << std::endl;
    }

    void dim(int level) {
        std::cout << "Lighting system dimmed to " << level << "%" << std::endl;
    }
};
