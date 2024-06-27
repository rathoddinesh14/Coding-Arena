// VideoSystem.h
#pragma once
#include <iostream>

class VideoSystem {
public:
    void on() {
        std::cout << "Video system is on." << std::endl;
    }

    void off() {
        std::cout << "Video system is off." << std::endl;
    }

    void setResolution(int width, int height) {
        std::cout << "Video system resolution set to " << width << "x" << height << std::endl;
    }
};
