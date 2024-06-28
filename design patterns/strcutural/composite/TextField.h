// TextField.h
#pragma once
#include "Component.h"
#include <iostream>

class TextField : public Component {
public:
    TextField(const std::string& value) : value(value) {}

    void render() const override {
        std::cout << "Rendering text field: " << value << std::endl;
    }

private:
    std::string value;
};
