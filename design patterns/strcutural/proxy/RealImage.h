#pragma once
#include "Image.h"
#include <iostream>

class RealImage : public Image {
public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk();
    }

    void display() const override {
        std::cout << "Displaying " << filename << std::endl;
    }

private:
    std::string filename;

    void loadFromDisk() {
        std::cout << "Loading " << filename << " from disk..." << std::endl;
    }
};
