/*
	Factory Method: Provides an interface for creating objects but allows subclasses to
					alter the type of objects that will be created. This promotes loose 
					coupling between client code and object creation, making the system 
					more flexible and easier to extend.

					Key Components:
					1. Product (Interface or Abstract Class): Defines the interface of 
					   objects created by the factory.
					2. ConcreteProduct: Implements the Product interface.
					3. Creator (Abstract Factory Class): Declares the factory method
					   that returns Product objects.
					4. ConcreteCreator - Implements the factory method to return an
					   instance of a ConcreteProduct.
*/

// Include necessary headers
#include <iostream>
#include <memory> 

// Define the Product Interface
class Animal {
public:
    virtual void speak() const = 0; // Pure virtual function
    virtual ~Animal() {}  // Virtual destructor for proper cleanup
};

// Create Concrete Products (Dog and Cat)
class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

// Define the Factory Class
class AnimalFactory {
public:
    // Factory Method
    static std::unique_ptr<Animal> createAnimal(const std::string& type) {
        if (type == "dog") {
            return std::make_unique<Dog>();
        }
        else if (type == "cat") {
            return std::make_unique<Cat>();
        }
        else {
            return nullptr; // Return nullptr if type is unknown
        }
    }
};

// Main function to demonstrate usage
int main() {
    // Create a Dog using the Factory Method
    std::unique_ptr<Animal> dog = AnimalFactory::createAnimal("dog");
    if (dog) dog->speak(); // Output: Woof!

    // Create a Cat using the Factory Method
    std::unique_ptr<Animal> cat = AnimalFactory::createAnimal("cat");
    if (cat) cat->speak(); // Output: Meow!

    return 0;
}