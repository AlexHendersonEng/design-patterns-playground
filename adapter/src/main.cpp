/*
    Adapter: The Adapter pattern allows objects with incompatible interfaces to work together.
             It acts as a bridge between two interfaces, allowing them to communicate. This
             is useful when integrating legacy or third-party code that cannot be modified.
*/

// Include necessary headers
#include <iostream>

 // Existing (Old) class with an incompatible interface
class OldPrinter {
public:
    void oldPrint() {
        std::cout << "Printing using OldPrinter" << std::endl;
    }
};

// Target interface (the new expected interface)
class NewPrinter {
public:
    virtual void print() = 0; // Pure virtual function (abstract method)
    virtual ~NewPrinter() = default;
};

// Adapter class that makes OldPrinter compatible with NewPrinter
class PrinterAdapter : public NewPrinter {
private:
    OldPrinter& oldPrinter; // Reference to an OldPrinter instance

public:
    // Constructor takes an OldPrinter instance
    PrinterAdapter(OldPrinter& printer) : oldPrinter(printer) {}

    // Implement the NewPrinter interface by calling oldPrint()
    void print() override {
        oldPrinter.oldPrint();
    }
};

// Client code that expects the NewPrinter interface
int main() {
    OldPrinter oldPrinter;               // Create an OldPrinter object
    PrinterAdapter adapter(oldPrinter);  // Create an adapter for OldPrinter

    adapter.print(); // Client uses the new interface, but internally calls oldPrint()

    return 0;
}
