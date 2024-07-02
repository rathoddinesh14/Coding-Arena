#pragma once
#include <string>

class Image {
public:
    virtual ~Image() {}
    virtual void display() const = 0;
};
