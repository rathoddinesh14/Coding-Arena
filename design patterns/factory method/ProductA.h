// ProductA.h
#include "Product.h"
#include <iostream>

class ProductA : public Product {
public:
    void use() override {
        std::cout << "Using ProductA" << std::endl;
    }
};