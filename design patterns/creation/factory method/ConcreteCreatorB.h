// ConcreteCreatorB.h
#include "Creator.h"
#include "ProductB.h"

class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() override {
        return new ProductB();
    }
};
