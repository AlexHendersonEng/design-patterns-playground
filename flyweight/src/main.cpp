/*
    Flyweight: Used to minimize memory usage or computational cost by sharing
               as much as possible with similar objects. It is particularly useful
               when dealing with a large number of objects that have shared
               (intrinsic) state and unique (extrinsic) state.
               
               Key Components:
               Flyweight: An interface that defines shared behavior.
               ConcreteFlyweight: Implements the Flyweight interface and stores
                                  intrinsic (shared) state.
               FlyweightFactory: Manages Flyweight objects and ensures that
                                 shared instances are reused.
               Client: Uses the Flyweight objects and passes extrinsic state
                       when needed.
*/

// Include necessary headers
#include <iostream>
#include <unordered_map>
#include <memory>

// Flyweight: Abstract class defining shared behavior
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
    virtual ~Flyweight() {}
};

// ConcreteFlyweight: Implements Flyweight and maintains intrinsic state
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState; // Shared state
public:
    ConcreteFlyweight(std::string state) : intrinsicState(state) {}
    void operation(const std::string& extrinsicState) const override {
        std::cout << "Flyweight with intrinsic state [" << intrinsicState
            << "] and extrinsic state [" << extrinsicState << "]\n";
    }
};

// FlyweightFactory: Creates and manages Flyweight objects
class FlyweightFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;
public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string& key) {
        // If the object doesn't exist, create and store it
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
        }
        return flyweights[key];
    }
};

// Client code
int main() {
	// Create a FlyweightFactory object
    FlyweightFactory factory;

    // Reusing the same Flyweight object for "A"
    auto fw1 = factory.getFlyweight("A");
    fw1->operation("First call");

    auto fw2 = factory.getFlyweight("A");
    fw2->operation("Second call");

    // Creating a new Flyweight object for "B"
    auto fw3 = factory.getFlyweight("B");
    fw3->operation("Another instance");

    return 0;
}
