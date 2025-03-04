/*
    Observer: Where an object (called the "Subject") maintains a list of its dependents ("Observers")
              and notifies them of any state changes. This pattern is useful when multiple objects 
              need to react to changes in another object's state without tightly coupling them.

              Key Components:
              Subject: Keeps track of observers and notifies them of state changes.
              Observer: Defines an interface for objects that should be notified of changes.
              ConcreteSubject: Implements the Subject and maintains the actual state.
              ConcreteObserver: Implements the Observer and reacts to notifications.
*/

// Include necessary headers
#include <iostream>
#include <vector>

// Forward declaration of Subject to avoid circular dependency
class Subject;

// Observer interface
class Observer {
public:
    virtual void update(int state) = 0; // Pure virtual function to be implemented by concrete observers
    virtual ~Observer() {} // Virtual destructor for proper cleanup
};

// Subject class (Observable)
class Subject {
private:
    std::vector<Observer*> observers; // List of observers
    int state; // State of the subject

public:
    void attach(Observer* observer) {
        observers.push_back(observer); // Add an observer
    }

    void detach(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update(state); // Notify all observers of state change
        }
    }

    void setState(int newState) {
        state = newState;
        notify(); // Notify observers whenever state changes
    }
};

// Concrete Observer
class ConcreteObserver : public Observer {
private:
    int observerID;
public:
    ConcreteObserver(int id) : observerID(id) {}
    void update(int state) override {
        std::cout << "Observer " << observerID << " notified. New state: " << state << std::endl;
    }
};

// Main function to demonstrate the pattern
int main() {
    Subject subject; // Create a Subject

    // Create Observers
    ConcreteObserver observer1(1);
    ConcreteObserver observer2(2);

    // Attach observers to subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Change subject state and notify observers
    std::cout << "Setting state to 10" << std::endl;
    subject.setState(10);

    // Detach one observer and change state again
    subject.detach(&observer1);
    std::cout << "Setting state to 20" << std::endl;
    subject.setState(20);

    return 0;
}
