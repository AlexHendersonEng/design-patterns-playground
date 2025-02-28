/*
    Bridge: Separates an abstraction from its implementation, allowing both to evolve
            independently. This is useful when we want to avoid a permanent binding
            between an abstraction and its implementation, making it easier to extend
            and modify.
*/

// Include necessary headers
#include <iostream>

// Implementation interface (defines the low-level behavior)
class Device {
public:
    virtual void turnOn() = 0;   // Pure virtual function
    virtual void turnOff() = 0;  // Pure virtual function
    virtual ~Device() {}
};

// Concrete Implementation 1: TV
class TV : public Device {
public:
    void turnOn() override {
        std::cout << "TV is now ON" << std::endl;
    }
    void turnOff() override {
        std::cout << "TV is now OFF" << std::endl;
    }
};

// Concrete Implementation 2: Radio
class Radio : public Device {
public:
    void turnOn() override {
        std::cout << "Radio is now ON" << std::endl;
    }
    void turnOff() override {
        std::cout << "Radio is now OFF" << std::endl;
    }
};

// Abstraction (high-level interface that delegates to the implementation)
class RemoteControl {
protected:
    Device* device;  // Pointer to implementation
public:
    RemoteControl(Device* dev) : device(dev) {}
    virtual void turnOn() {
        device->turnOn();
    }
    virtual void turnOff() {
        device->turnOff();
    }
    virtual ~RemoteControl() {}
};

// Extended Abstraction: Advanced Remote with extra functionality
class AdvancedRemote : public RemoteControl {
public:
    AdvancedRemote(Device* dev) : RemoteControl(dev) {}
    void mute() {
        std::cout << "Device is now MUTED" << std::endl;
    }
};

int main() {
	// Create TV and Radio objects
    TV myTV;
    Radio myRadio;

    // Basic remote controlling a TV
    RemoteControl basicRemote(&myTV);
    basicRemote.turnOn();
    basicRemote.turnOff();

    // Advanced remote controlling a Radio
    AdvancedRemote advancedRemote(&myRadio);
    advancedRemote.turnOn();
    advancedRemote.mute();
    advancedRemote.turnOff();

    return 0;
}