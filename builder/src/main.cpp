/*
Builder: Used to construct complex objects step by step. It allows for the creation
         of different representations of an object using the same building process.
         
         Key Components:
         - Product: The complex object being built.
         - Builder Interface: Specifies steps to build the product.
         - Concrete Builder: Implements the steps defined in the Builder Interface.
         - Director (Optional): Directs the building process.
*/

// Include headers
#include <iostream>
#include <string>

// Product: The complex object being built
class Product {
public:
    std::string partA;
    std::string partB;
    void show() {
        std::cout << "Product Parts: " << partA << ", " << partB << std::endl;
    }
};

// Builder Interface
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product* getResult() = 0;
    virtual ~Builder() {}
};

// Concrete Builder
class ConcreteBuilder : public Builder {
private:
    Product* product;
public:
    ConcreteBuilder() { product = new Product(); }
    void buildPartA() override { product->partA = "Part A"; }
    void buildPartB() override { product->partB = "Part B"; }
    Product* getResult() override { return product; }
};

// Director (Optional)
class Director {
public:
    void construct(Builder& builder) {
        builder.buildPartA();
        builder.buildPartB();
    }
};

// Client Code
int main() {
	// Create the builder and director
    ConcreteBuilder builder;
    Director director;

    // The director constructs the product using the builder
    director.construct(builder);

    // Retrieve the finished product
    Product* product = builder.getResult();
    product->show();

    // Clean up
    delete product;
    return 0;
}


