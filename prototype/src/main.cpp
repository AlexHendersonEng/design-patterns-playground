/*
    Prototype: Allows cloning of objects without depending on their concrete
               classes. Instead of creating new objects from scratch, we create
               a new object by copying an existing one (a prototype).
*/

// Include the necessary headers
#include <iostream>
#include <memory>

 // Define the Prototype Interface
class Prototype {
public:
    virtual ~Prototype() {}
    virtual std::unique_ptr<Prototype> clone() const = 0; // Clone method
    virtual void show() const = 0; // For demonstration purposes
};

// Implement Concrete Prototypes
class ConcretePrototypeA : public Prototype {
private:
    int value;
public:
    ConcretePrototypeA(int val) : value(val) {}

    // Override clone method
    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototypeA>(this->value); // Copy current object
    }

    void show() const override {
        std::cout << "ConcretePrototypeA with value: " << value << std::endl;
    }
};

// Using the Prototype
int main() {
    // Create an initial prototype instance
    std::unique_ptr<Prototype> prototype = std::make_unique<ConcretePrototypeA>(42);

    // Clone the prototype
    std::unique_ptr<Prototype> clonedPrototype = prototype->clone();

    // Show the cloned 
    clonedPrototype->show();

    return 0;
}
