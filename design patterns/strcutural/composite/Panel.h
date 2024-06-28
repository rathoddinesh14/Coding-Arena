// Panel.h
#pragma once
#include "Component.h"
#include <vector>
#include <iostream>

class Panel : public Component {
public:
    void render() const override {
        std::cout << "Rendering panel:" << std::endl;
        for (const Component* component : children) {
            component->render();
        }
    }

    void add(Component* component) override {
        children.push_back(component);
    }

    void remove(Component* component) override {
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }

    Component* getChild(int index) override {
        if (index < 0 || index >= children.size()) return nullptr;
        return children[index];
    }

private:
    std::vector<Component*> children;
};
