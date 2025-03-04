/*
    Memento: Allows an object to save and restore its previous state without exposing
             its internal structure. It is often used in scenarios where undo
             functionality is required.

             Key Components:
             Originator: The object whose state needs to be saved and restored.
             Memento: A snapshot of the Originator's state.
             Caretaker: Manages the saved states (mementos) but does not modify them.
*/

// Include necessary headers
#include <iostream>
#include <vector>

// Memento class - Stores a snapshot of the Originator's state
class Memento {
private:
    int state; // Internal state of the Originator
public:
    Memento(int s) : state(s) {} // Constructor to set state
    int getState() const { return state; } // Getter for state
};

// Originator class - Creates and restores mementos
class Originator {
private:
    int state; // Internal state
public:
    void setState(int s) { // Modify the state
        state = s;
        std::cout << "State set to: " << state << std::endl;
    }
    Memento saveToMemento() { // Save current state to Memento
        return Memento(state);
    }
    void restoreFromMemento(const Memento& m) { // Restore state from Memento
        state = m.getState();
        std::cout << "State restored to: " << state << std::endl;
    }
};

// Caretaker class - Manages mementos
class Caretaker {
private:
    std::vector<Memento> history; // Stores mementos
public:
    void addMemento(const Memento& m) { // Save a memento
        history.push_back(m);
    }
    Memento getMemento(int index) { // Retrieve a memento
        return history[index];
    }
};

int main() {
	// Create instances of Originator and Caretaker
    Originator originator;
    Caretaker caretaker;

    // Change state and save it
    originator.setState(1);
    caretaker.addMemento(originator.saveToMemento());

    originator.setState(2);
    caretaker.addMemento(originator.saveToMemento());

    originator.setState(3);

    // Restore a previous state
    originator.restoreFromMemento(caretaker.getMemento(0)); // Restores to state 1

    return 0;
}
