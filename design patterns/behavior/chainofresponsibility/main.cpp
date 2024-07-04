#include <iostream>
#include <string>

// Base Handler Class
class Handler {
protected:
    Handler* nextHandler;

public:
    Handler() : nextHandler(nullptr) {}
    virtual ~Handler() {}

    void setNextHandler(Handler* next) {
        nextHandler = next;
    }

    virtual void handleRequest(const std::string& request) {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

// Concrete Handler 1: Base Handler
class BaseHandler : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Base Request") {
            std::cout << "BaseHandler: Handling request: " << request << std::endl;
        } else {
            std::cout << "BaseHandler: Passing request to next handler." << std::endl;
            Handler::handleRequest(request);
        }
    }
};

// Concrete Handler 2: Manager
class Manager : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Manager Request") {
            std::cout << "Manager: Handling request: " << request << std::endl;
        } else {
            std::cout << "Manager: Passing request to next handler." << std::endl;
            Handler::handleRequest(request);
        }
    }
};

// Concrete Handler 3: Director
class Director : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Director Request") {
            std::cout << "Director: Handling request: " << request << std::endl;
        } else {
            std::cout << "Director: Passing request to next handler." << std::endl;
            Handler::handleRequest(request);
        }
    }
};

int main() {
    // Create handlers
    BaseHandler baseHandler;
    Manager manager;
    Director director;

    // Set up the chain
    baseHandler.setNextHandler(&manager);
    manager.setNextHandler(&director);

    // Create requests
    std::string requests[] = {"Base Request", "Manager Request", "Director Request", "Unknown Request"};

    // Pass requests to the chain
    for (const std::string& request : requests) {
        std::cout << "Client: Sending request: " << request << std::endl;
        baseHandler.handleRequest(request);
        std::cout << std::endl;
    }

    return 0;
}
