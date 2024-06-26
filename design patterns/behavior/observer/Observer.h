// Observer.h
#pragma once

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(int value) = 0;
};
