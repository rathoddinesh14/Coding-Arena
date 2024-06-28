// Button.h
#pragma once
#include "Component.h"
#include <iostream>

class Button : public Component {
public:
    Button(const std::string& text) : text(text) {}

    void render() const override {
        std::cout << "Rendering button: " << text << std::endl;
    }

private:
    std::string text;
};
