/*
    Decorator: Allows behavior to be added to an individual object, dynamically,
               without affecting the behavior of other objects of the same class.
               It is useful for extending functionalities in a flexible and 
               reusable way without modifying existing code.

               Key Components:
               Component (Base Interface): Defines the interface for objects that
                                           can have responsibilities added to
                                           them dynamically.
               Concrete Component: Implements the base interface and provides the
                                   core behavior.
               Decorator (Abstract Class): Implements the base interface and has a
                                           reference to a component object.
               Concrete Decorators: Extend functionality of the component by adding 
                                    extra behaviors.
*/

// Include necessary headers
#include <iostream>

// Create the base Component interface
class Component {
public:
    virtual void operation() = 0; // Pure virtual function
    virtual ~Component() {}       // Virtual destructor for proper cleanup
};

// Implement a Concrete Component
class ConcreteComponent : public Component {
public:
    void operation() override {
        std::cout << "ConcreteComponent: Base Operation\n";
    }
};

// Create an Abstract Decorator that wraps a Component
class Decorator : public Component {
protected:
    Component* component; // Pointer to a Component object
public:
    Decorator(Component* comp) : component(comp) {}
    void operation() override {
        component->operation(); // Delegate to the wrapped object
    }
    virtual ~Decorator() {
        delete component; // Clean up dynamically allocated memory
    }
};

// Implement Concrete Decorators that extend functionality
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}
    void operation() override {
        Decorator::operation(); // Call base operation
        std::cout << "ConcreteDecoratorA: Added Behavior A\n";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}
    void operation() override {
        Decorator::operation(); // Call base operation
        std::cout << "ConcreteDecoratorB: Added Behavior B\n";
    }
};

// Demonstrate usage of the decorator pattern
int main() {
    // Create a simple ConcreteComponent
    Component* simple = new ConcreteComponent();
    std::cout << "Simple Component:\n";
    simple->operation();
    std::cout << "\n";

    // Wrap the component with ConcreteDecoratorA
    Component* decoratedA = new ConcreteDecoratorA(simple);
    std::cout << "Component with ConcreteDecoratorA:\n";
    decoratedA->operation();
    std::cout << "\n";

    // Further wrap it with ConcreteDecoratorB
    Component* decoratedB = new ConcreteDecoratorB(decoratedA);
    std::cout << "Component with ConcreteDecoratorA and ConcreteDecoratorB:\n";
    decoratedB->operation();
    std::cout << "\n";

    // Clean up
    delete decoratedB; // This will also delete decoratedA and simple

    return 0;
}