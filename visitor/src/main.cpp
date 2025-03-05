/*
    Visitor: Allows adding new behaviors to existing class hierarchies without modifying
             the original classes. It achieves this by using a visitor class that implements
             the new behavior and is accepted by elements of the hierarchy through a common interface.

             Key Components:
             Visitor Interface: Declares visit methods for each type of element in the hierarchy.
             Concrete Visitor: Implements the visit methods to define new behavior.
             Element Interface: Declares an accept method that takes a visitor.
             Concrete Elements: Implement the accept method by calling the appropriate visitor method.
*/

// Include necessary headers
#include <iostream>

// Forward declarations of concrete element classes
class ElementA;
class ElementB;

// Visitor Interface
class Visitor {
public:
    virtual void visit(ElementA& element) = 0; // Visit method for ElementA
    virtual void visit(ElementB& element) = 0; // Visit method for ElementB
};

// Element Interface
class Element {
public:
    virtual void accept(Visitor& visitor) = 0; // Accept method for Visitor
};

// Concrete Element A
class ElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this); // Calls the appropriate visit method
    }
};

// Concrete Element B
class ElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this); // Calls the appropriate visit method
    }
};

// Concrete Visitor
class ConcreteVisitor : public Visitor {
public:
    void visit(ElementA& element) override {
        std::cout << "Visiting ElementA" << std::endl;
    }

    void visit(ElementB& element) override {
        std::cout << "Visiting ElementB" << std::endl;
    }
};

int main() {
	// Create instances of elements and visitor
    ElementA a;
    ElementB b;
    ConcreteVisitor visitor;

	// Accept the visitor
    a.accept(visitor); // Visiting ElementA
    b.accept(visitor); // Visiting ElementB

    return 0;
}
