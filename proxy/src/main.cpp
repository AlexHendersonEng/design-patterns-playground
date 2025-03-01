/*
    Proxy: Provides a surrogate or placeholder for another object to control access to it.
*/

// Include necessary headers
#include <iostream>

// Subject Interface
class Subject {
public:
    virtual void request() = 0; // Pure virtual function
    virtual ~Subject() {}
};

// RealSubject: The actual object that performs the real work
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request.\n";
    }
};

// Proxy: Controls access to RealSubject
class Proxy : public Subject {
private:
    RealSubject* realSubject; // Pointer to the real object

public:
    Proxy() : realSubject(nullptr) {} // Constructor initializes to null

    ~Proxy() {
        delete realSubject; // Cleanup memory when proxy is destroyed
    }

    void request() override {
        // Lazy initialization: Only create RealSubject when needed
        if (!realSubject) {
            std::cout << "Proxy: Creating RealSubject instance.\n";
            realSubject = new RealSubject();
        }

        std::cout << "Proxy: Forwarding request to RealSubject.\n";
        realSubject->request();
    }
};

// Client code
int main() {
    Proxy proxy;
    std::cout << "Client: Requesting through Proxy...\n";
    proxy.request(); // First call creates the RealSubject
    std::cout << "Client: Requesting again...\n";
    proxy.request(); // Second call reuses the existing RealSubject
    return 0;
}