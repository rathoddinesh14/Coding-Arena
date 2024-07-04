#pragma once
#include "CoffeeDecorator.h"

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return decoratedCoffee->getDescription() + ", Sugar";
    }

    double cost() const override {
        return decoratedCoffee->cost() + 0.2; // additional cost for sugar
    }
};