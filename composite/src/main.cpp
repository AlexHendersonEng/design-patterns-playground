/*
    Composite: Allows for treating individual objects and compositions of objects uniformly.
               It is particularly useful when dealing with hierarchical structures like
               trees. This pattern allows clients to work with complex structures without 
               needing to differentiate between individual objects and compositions.

               Components:
               - Component (Base class): Declares the common interface for all objects
                                         in the composition.
               - Leaf (Concrete class): Represents an individual object that has no children.
               - Composite (Concrete class): Represents a complex object that can contain
                                             children (other Components).
*/

// Include necessary headers
#include <iostream>
#include <vector>
#include <memory>

 // Component: Abstract base class
class FileSystemComponent {
public:
    virtual void showDetails(int indent = 0) const = 0; // Pure virtual function
    virtual ~FileSystemComponent() = default;
};

// Leaf: Represents individual file
class File : public FileSystemComponent {
private:
    std::string name;
public:
    File(const std::string& name) : name(name) {}
    void showDetails(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "File: " << name << '\n';
    }
};

// Composite: Represents a directory that can contain files or other directories
class Directory : public FileSystemComponent {
private:
    std::string name;
    std::vector<std::shared_ptr<FileSystemComponent>> children;
public:
    Directory(const std::string& name) : name(name) {}

    void add(std::shared_ptr<FileSystemComponent> component) {
        children.push_back(component);
    }

    void showDetails(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Directory: " << name << '\n';
        for (const auto& child : children) {
            child->showDetails(indent + 2); // Indent children for hierarchy visualization
        }
    }
};

int main() {
    // Creating files
    auto file1 = std::make_shared<File>("file1.txt");
    auto file2 = std::make_shared<File>("file2.txt");

    // Creating directories
    auto dir1 = std::make_shared<Directory>("dir1");
    auto dir2 = std::make_shared<Directory>("dir2");

    // Building the file system structure
    dir1->add(file1); // dir1 contains file1
    dir2->add(file2); // dir2 contains file2
    dir1->add(dir2);  // dir1 contains dir2

    // Displaying the structure
    dir1->showDetails();

    return 0;
}