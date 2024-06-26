#include "ConcreteSubject.h"
#include "ConcreteObserver.h"

int main() {
    ConcreteSubject subject;

    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setValue(10);
    subject.setValue(20);

    subject.detach(&observer1);

    subject.setValue(30);

    return 0;
}
