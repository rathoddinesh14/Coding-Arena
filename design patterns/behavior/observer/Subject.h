// Subject.h
#pragma once
#include "Observer.h"
#include <vector>

class Subject {
public:
    virtual ~Subject() {}

    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(int value) {
        for (Observer* observer : observers) {
            observer->update(value);
        }
    }

private:
    std::vector<Observer*> observers;
};