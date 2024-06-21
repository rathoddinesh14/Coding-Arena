// ConcreteCreatorA.h
#include "Creator.h"
#include "ProductA.h"

class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() override {
        return new ProductA();
    }
};