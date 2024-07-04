#pragma once
#include "Coffee.h"

class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }

    double cost() const override {
        return 2.0; // base cost of simple coffee
    }
};
