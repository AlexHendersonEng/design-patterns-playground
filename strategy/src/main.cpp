/*
    Strategy: Defines a family of algorithms, encapsulates each one,
              and makes them interchangeable. This pattern allows the 
              algorithm to be selected at runtime.
*/

// Include necessary headers
#include <iostream>
#include <memory> // For std::unique_ptr

 // Define the Strategy interface
class Strategy {
public:
    virtual void execute() const = 0; // Pure virtual function
    virtual ~Strategy() = default;   // Virtual destructor for proper cleanup
};

// Implement Concrete Strategies
class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Strategy B" << std::endl;
    }
};

// Implement Context class that uses a strategy
class Context {
private:
    std::unique_ptr<Strategy> strategy; // Smart pointer to manage strategy object

public:
    // Constructor to initialize with a strategy
    Context(std::unique_ptr<Strategy> strat) : strategy(std::move(strat)) {}

    // Method to change strategy dynamically
    void setStrategy(std::unique_ptr<Strategy> strat) {
        strategy = std::move(strat);
    }

    // Execute the strategy
    void executeStrategy() const {
        if (strategy) {
            strategy->execute();
        }
        else {
            std::cout << "No strategy set!" << std::endl;
        }
    }
};

// Demonstrate usage
int main() {
    // Create a context with Strategy A
    Context context(std::make_unique<ConcreteStrategyA>());
    context.executeStrategy(); // Outputs: Executing Strategy A

    // Change strategy to Strategy B
    context.setStrategy(std::make_unique<ConcreteStrategyB>());
    context.executeStrategy(); // Outputs: Executing Strategy B

    return 0;
}
