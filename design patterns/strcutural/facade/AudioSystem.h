// AudioSystem.h
#pragma once
#include <iostream>

class AudioSystem {
public:
    void on() {
        std::cout << "Audio system is on." << std::endl;
    }

    void off() {
        std::cout << "Audio system is off." << std::endl;
    }

    void setVolume(int level) {
        std::cout << "Audio system volume set to " << level << std::endl;
    }
};
