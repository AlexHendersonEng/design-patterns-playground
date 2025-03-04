/*
    State: Allows an object to change its behavior when its internal state changes.
           This example demonstrates a simple implementation of a Light Switch that
           can be either "On" or "Off".
*/

// Include necessary headers
#include <iostream>

// Forward declaration of class Context
class LightSwitch;

// State Interface
class State {
public:
    virtual void turnOn(LightSwitch* ls) = 0; // Pure virtual function for turning on
    virtual void turnOff(LightSwitch* ls) = 0; // Pure virtual function for turning off
    virtual ~State() {} // Virtual destructor for proper cleanup
};

// Concrete State: Light is On
class OnState : public State {
public:
    void turnOn(LightSwitch* ls) override;
    void turnOff(LightSwitch* ls) override;
};

// Concrete State: Light is Off
class OffState : public State {
public:
    void turnOn(LightSwitch* ls) override;
    void turnOff(LightSwitch* ls) override;
};

// Context: Light Switch
class LightSwitch {
private:
    State* state; // Current state of the Light Switch
public:
    LightSwitch() { state = new OffState(); } // Default state is Off
    ~LightSwitch() { delete state; } // Cleanup state

    void setState(State* newState) {
        delete state; // Delete the old state
        state = newState; // Assign the new state
    }

    void turnOn() { state->turnOn(this); }
    void turnOff() { state->turnOff(this); }
};

// Implementations of OnState methods
void OnState::turnOn(LightSwitch* ls) {
    std::cout << "The light is already ON." << std::endl;
}
void OnState::turnOff(LightSwitch* ls) {
    std::cout << "Turning OFF the light." << std::endl;
    ls->setState(new OffState()); // Transition to OffState
}

// Implementations of OffState methods
void OffState::turnOn(LightSwitch* ls) {
    std::cout << "Turning ON the light." << std::endl;
    ls->setState(new OnState()); // Transition to OnState
}
void OffState::turnOff(LightSwitch* ls) {
    std::cout << "The light is already OFF." << std::endl;
}

// Main function to demonstrate the State pattern
int main() {
    LightSwitch ls; // Create a LightSwitch object

    ls.turnOn();  // Turns the light ON
    ls.turnOn();  // Already ON, should print a message
    ls.turnOff(); // Turns the light OFF
    ls.turnOff(); // Already OFF, should print a message

    return 0;
}