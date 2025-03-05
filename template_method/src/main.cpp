/*
    Template Method: Defines the skeleton of an algorithm in a base class and allows subclasses
                     to override specific steps of the algorithm without changing its overall structure.

                     Key Components:
                     Base Class (abstract class): Provides a template method that defines the steps of an algorithm.
                                                  Some steps are implemented in the base class, while others are left
                                                  as abstract (pure virtual) functions.
                     Subclasses: Override the abstract methods to provide specific implementations.
*/

// Include necessary headers
#include <iostream>

// Abstract base class defining the template method
class Beverage {
public:
    // Template method defining the algorithm structure
    void prepareRecipe() {
        boilWater();
        brew();            // Step to be implemented by subclasses
        pourInCup();
        addCondiments();   // Step to be implemented by subclasses
    }

protected:
    // Common steps implemented in base class
    void boilWater() {
        std::cout << "Boiling water..." << std::endl;
    }

    void pourInCup() {
        std::cout << "Pouring into cup..." << std::endl;
    }

    // Steps to be defined by subclasses
    virtual void brew() = 0;           // Pure virtual function (abstract method)
    virtual void addCondiments() = 0;  // Pure virtual function (abstract method)
};

// Concrete subclass for making tea
class Tea : public Beverage {
protected:
    void brew() override {
        std::cout << "Steeping the tea..." << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding lemon..." << std::endl;
    }
};

// Concrete subclass for making coffee
class Coffee : public Beverage {
protected:
    void brew() override {
        std::cout << "Dripping coffee through filter..." << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk..." << std::endl;
    }
};

// Main function to demonstrate the template method pattern
int main() {
	// Create instance of Tea and call the template method
    std::cout << "Making tea:" << std::endl;
    Tea tea;
    tea.prepareRecipe();

    // Create instance of Coffee and call the template method
    std::cout << "\nMaking coffee:" << std::endl;
    Coffee coffee;
    coffee.prepareRecipe();

    return 0;
}
