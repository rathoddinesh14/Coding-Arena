#pragma once
#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return decoratedCoffee->getDescription() + ", Milk";
    }

    double cost() const override {
        return decoratedCoffee->cost() + 0.5; // additional cost for milk
    }
};