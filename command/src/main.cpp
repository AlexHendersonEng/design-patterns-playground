/*
    Command: Encapsulates a request as an object, thereby allowing for parameterization 
             of clients, queuing of requests, and logging of operations.
            
             Key Components:
             Command (interface): Declares an execution method.
             ConcreteCommand: Implements the Command interface, linking an action and a receiver.
             Receiver: The actual business logic that will execute the request.
             Invoker: Stores and executes commands.
             Client: Creates and configures commands.
 */

// Include necessary headers
#include <iostream>

// Command Interface
class Command {
public:
    virtual void execute() = 0; // Pure virtual function to execute command
    virtual ~Command() {}
};

// Receiver (Performs actual operations)
class Light {
public:
    void turnOn() { std::cout << "Light is ON" << std::endl; }
    void turnOff() { std::cout << "Light is OFF" << std::endl; }
};

// Concrete Commands
class TurnOnCommand : public Command {
private:
    Light& light;
public:
    TurnOnCommand(Light& l) : light(l) {}
    void execute() override { light.turnOn(); } // Execute action on Receiver
};

class TurnOffCommand : public Command {
private:
    Light& light;
public:
    TurnOffCommand(Light& l) : light(l) {}
    void execute() override { light.turnOff(); } // Execute action on Receiver
};

// Invoker (Triggers commands)
class RemoteControl {
private:
    Command* command;
public:
    void setCommand(Command* cmd) { command = cmd; }
    void pressButton() {
        if (command) command->execute();
    }
};

// Client
int main() {
    Light light; // Receiver
    TurnOnCommand turnOn(light);
    TurnOffCommand turnOff(light);
    RemoteControl remote;

    remote.setCommand(&turnOn);
    remote.pressButton(); // Output: Light is ON

    remote.setCommand(&turnOff);
    remote.pressButton(); // Output: Light is OFF

    return 0;
}
