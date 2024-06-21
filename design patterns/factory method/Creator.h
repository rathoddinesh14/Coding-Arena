// Creator.h
#pragma once
#include "Product.h"

class Creator {
public:
    virtual ~Creator() {}
    virtual Product* createProduct() = 0;
};
