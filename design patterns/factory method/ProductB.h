// ProductB.h
#include "Product.h"
#include <iostream>

class ProductB : public Product {
public:
    void use() override {
        std::cout << "Using ProductB" << std::endl;
    }
};
