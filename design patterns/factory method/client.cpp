// main.cpp
#include "ConcreteCreatorA.h"
#include "ConcreteCreatorB.h"

void clientCode(Creator& creator) {
    Product* product = creator.createProduct();
    product->use();
    delete product;
}

int main() {
    ConcreteCreatorA creatorA;
    clientCode(creatorA);

    ConcreteCreatorB creatorB;
    clientCode(creatorB);

    return 0;
}
