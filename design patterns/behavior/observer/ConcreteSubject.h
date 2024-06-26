// ConcreteSubject.h
#pragma once
#include "Subject.h"

class ConcreteSubject : public Subject {
public:
    void setValue(int value) {
        this->value = value;
        notify(value);
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};
