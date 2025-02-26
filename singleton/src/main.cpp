/*
    Singleton: Ensures that a class has only one instance and provides a
               global point of access to that instance.
               
               Key Features:
               - A private constructor to prevent direct instantiation.
               - A static method to get the single instance.
               - A static member to hold the instance.
               - Deleting copy constructor and assignment operator to prevent duplication.
*/

// Include standard headers
#include <iostream>

class Singleton {
private:
    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton Instance Created" << std::endl;
    }

    // Deleting copy constructor to prevent copying
    Singleton(const Singleton&) = delete;

    // Deleting assignment operator to prevent assignment
    Singleton& operator=(const Singleton&) = delete;

    // Static pointer to hold the single instance
    static Singleton* instance;

public:
    // Static method to provide access to the single instance
    static Singleton* getInstance() {
        if (instance == nullptr) { // Create instance only if it doesn't exist
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    // Access Singleton instance
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // Verify that both instances are the same
    if (s1 == s2) {
        std::cout << "Both instances are the same!" << std::endl;
    }

    return 0;
}
