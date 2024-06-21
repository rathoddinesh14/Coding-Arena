// Strategy.h
#pragma once
#include <vector>

class Strategy {
public:
    virtual ~Strategy() {}
    virtual void sort(std::vector<int>& data) = 0;
};
