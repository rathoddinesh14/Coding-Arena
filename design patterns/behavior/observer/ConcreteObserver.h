// ConcreteObserver.h
#pragma once
#include "Observer.h"
#include <iostream>

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(int value) override {
        std::cout << "Observer " << name << " received update: " << value << std::endl;
    }

private:
    std::string name;
};
