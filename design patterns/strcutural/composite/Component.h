// Component.h
#pragma once
#include <string>

class Component {
public:
    virtual ~Component() {}
    virtual void render() const = 0;
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual Component* getChild(int index) { return nullptr; }
};
