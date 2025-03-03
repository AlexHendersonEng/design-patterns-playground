/*
    Mediator: Used to reduce direct dependencies between objects by introducing a mediator object
              that handles communication between them. This promotes loose coupling and makes the
              system more maintainable.
 
              Key Components:
              Mediator: Defines an interface for communication between components.
              ConcreteMediator: Implements the Mediator interface and coordinates communication
                                between components.
              Component: Represents an object that interacts with other components via the Mediator.
              ConcreteComponent: A specific implementation of a component.
 */

// Include necessary headers
#include <iostream>
#include <string>

// Forward declaration
class Mediator;

// Base Component class
class Component {
protected:
    Mediator* mediator; // Pointer to mediator
public:
    Component(Mediator* med) : mediator(med) {}
    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message) = 0;
};

// Mediator Interface
class Mediator {
public:
    virtual void notify(Component* sender, const std::string& message) = 0;
};

// Concrete Component A
class ComponentA : public Component {
public:
    ComponentA(Mediator* med) : Component(med) {}
    void send(const std::string& message) override {
        std::cout << "ComponentA sends: " << message << std::endl;
        mediator->notify(this, message);
    }
    void receive(const std::string& message) override {
        std::cout << "ComponentA receives: " << message << std::endl;
    }
};

// Concrete Component B
class ComponentB : public Component {
public:
    ComponentB(Mediator* med) : Component(med) {}
    void send(const std::string& message) override {
        std::cout << "ComponentB sends: " << message << std::endl;
        mediator->notify(this, message);
    }
    void receive(const std::string& message) override {
        std::cout << "ComponentB receives: " << message << std::endl;
    }
};

// Concrete Mediator that coordinates communication between components
class ConcreteMediator : public Mediator {
private:
    ComponentA* componentA;
    ComponentB* componentB;
public:
    void setComponentA(ComponentA* a) { componentA = a; }
    void setComponentB(ComponentB* b) { componentB = b; }

    void notify(Component* sender, const std::string& message) override {
        // Mediator decides how to forward the message
        if (sender == componentA) {
            componentB->receive(message);
        }
        else if (sender == componentB) {
            componentA->receive(message);
        }
    }
};

// Main function to demonstrate the Mediator pattern
int main() {
	// Create mediator and components
    ConcreteMediator mediator;
    ComponentA a(&mediator);
    ComponentB b(&mediator);

	// Set components in the mediator
    mediator.setComponentA(&a);
    mediator.setComponentB(&b);

    // Communication via the mediator
    a.send("Hello from A!");
    b.send("Hi from B!");

    return 0;
}
