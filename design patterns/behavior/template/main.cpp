#include <iostream>

// Base class with the template method
class Beverage {
public:
    // Template method
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    // Common steps
    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }

    // Steps to be implemented by subclasses
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
};

// Derived class for Tea
class Tea : public Beverage {
public:
    void brew() override {
        std::cout << "Steeping the tea" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding lemon" << std::endl;
    }
};

// Derived class for Coffee
class Coffee : public Beverage {
public:
    void brew() override {
        std::cout << "Dripping coffee through filter" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk" << std::endl;
    }
};

int main() {
    Tea tea;
    Coffee coffee;

    std::cout << "Preparing tea..." << std::endl;
    tea.prepareRecipe();

    std::cout << "\nPreparing coffee..." << std::endl;
    coffee.prepareRecipe();

    return 0;
}
