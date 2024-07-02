#pragma once
#include "Coffee.h"

class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    std::string getDescription() const override {
        return decoratedCoffee->getDescription();
    }

    double cost() const override {
        return decoratedCoffee->cost();
    }
};
