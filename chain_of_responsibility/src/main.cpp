/*
    Chain of Responsibility: Allows multiple objects to handle a request without the sender
                             needing to know which object will handle it. The request is passed
                             along a chain of handlers until one of them processes it or the chain ends.
*/

// Include necessary headers
#include <iostream>

// Abstract Handler class
class Handler {
protected:
    Handler* nextHandler; // Pointer to the next handler in the chain

    Handler() : nextHandler(nullptr) {}
    virtual ~Handler() = default;

    // Virtual function to handle request, overridden by concrete handlers
    virtual void handleRequest(int request) {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        }
        else {
            std::cout << "Request " << request << " could not be handled.\n";
        }
    }

public:
    void setNextHandler(Handler* next) { nextHandler = next; }
};

// Concrete Handler 1: Handles requests less than 10
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(int request) override {
        if (request < 10) {
            std::cout << "ConcreteHandler1 handled request " << request << "\n";
        }
        else {
            Handler::handleRequest(request);
        }
    }
};

// Concrete Handler 2: Handles requests between 10 and 20
class ConcreteHandler2 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandler2 handled request " << request << "\n";
        }
        else {
            Handler::handleRequest(request);
        }
    }
};

// Concrete Handler 3: Handles requests between 20 and 30
class ConcreteHandler3 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 20 && request < 30) {
            std::cout << "ConcreteHandler3 handled request " << request << "\n";
        }
        else {
            Handler::handleRequest(request);
        }
    }
};

// Client code
int main() {
    // Creating handlers
    ConcreteHandler1 handler1;
    ConcreteHandler2 handler2;
    ConcreteHandler3 handler3;

    // Setting up the chain of responsibility
    handler1.setNextHandler(&handler2);
    handler2.setNextHandler(&handler3);

    // Test requests
    int requests[] = { 5, 15, 25, 35 };
    for (int req : requests) {
        handler1.handleRequest(req); // Start from the first handler
    }

    return 0;
}