/*
	Abstract Factory: The Abstract Factory pattern provides an interface for creating 
                      families of related objects without specifying their concrete classes.
                      It is useful when a system needs to be independent of how its objects
                      are created, composed, and represented.
*/

// Include standard libraries
#include <iostream>

// Create an abstract product (base class for products)
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual function (must be implemented by subclasses)
    virtual ~Animal() {} // Virtual destructor
};

// Create concrete products (specific types of Animals)
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Create an abstract factory (base class for factories)
class AnimalFactory {
public:
    virtual Animal* createAnimal() = 0; // Pure virtual function
    virtual ~AnimalFactory() {} // Virtual destructor
};

// Create concrete factories (factories that produce specific animals)
class DogFactory : public AnimalFactory {
public:
    Animal* createAnimal() override {
        return new Dog(); // Creates a Dog object
    }
};

class CatFactory : public AnimalFactory {
public:
    Animal* createAnimal() override {
        return new Cat(); // Creates a Cat object
    }
};

// Use the factory to create objects
int main() {
    AnimalFactory* factory1 = new DogFactory(); // Create a Dog factory
    Animal* dog = factory1->createAnimal(); // Create a Dog
    dog->makeSound(); // Output: Woof!
    delete dog;
    delete factory1;

    AnimalFactory* factory2 = new CatFactory(); // Create a Cat factory
    Animal* cat = factory2->createAnimal(); // Create a Cat
    cat->makeSound(); // Output: Meow!
    delete cat;
    delete factory2;

    return 0;
}