#include <iostream>
#include <functional>

// Function that prints "Hello, World!"
void sayHello() {
    std::cout << "Hello, World!" << std::endl;
}

// Higher-order function that takes a function as an argument and executes it
void executeFunction(const std::function<void()>& func) {
    func();
}

int main() {
    // Using a regular function
    executeFunction(sayHello);

    // Using a lambda function
    auto sayHelloLambda = []() {
        std::cout << "Hello, World!" << std::endl;
    };
    executeFunction(sayHelloLambda);

    return 0;
}
