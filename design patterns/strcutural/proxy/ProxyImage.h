#pragma once
#include "Image.h"
#include "RealImage.h"

class ProxyImage : public Image {
public:
    ProxyImage(const std::string& filename) : filename(filename), realImage(nullptr) {}

    ~ProxyImage() {
        delete realImage;
    }

    void display() const override {
        if (!realImage) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }

private:
    std::string filename;
    mutable RealImage* realImage;
};
