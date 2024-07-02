#include <iostream>
#include "SimpleCoffee.h"
#include "MilkDecorator.h"
#include "SugarDecorator.h"

int main() {
    Coffee* myCoffee = new SimpleCoffee();
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    myCoffee = new MilkDecorator(myCoffee);
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    myCoffee = new SugarDecorator(myCoffee);
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    delete myCoffee;
    return 0;
}
