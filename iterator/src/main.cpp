/*
    Iterator: Provides a way to access the elements of an aggregate object (such as a collection)
              sequentially without exposing its underlying representation. It helps separate the
              logic of iterating over a collection from the collection itself.

              Key Components:
              Iterator (Abstract Interface): Defines an interface for accessing elements.
              Concrete Iterator: Implements the Iterator interface and keeps track of the
                                 current position.
              Aggregate (Collection Interface): Defines an interface for creating an iterator.
              Concrete Aggregate: Implements the Aggregate interface and stores the elements.
 */

// Include necessary headers
#include <iostream>
#include <vector>

// Define an Iterator Interface
class Iterator {
public:
    virtual bool hasNext() = 0; // Check if there is a next element
    virtual int next() = 0;     // Return the next element
    virtual ~Iterator() {}
};

// Create a Concrete Iterator
class ConcreteIterator : public Iterator {
private:
    std::vector<int> collection;
    size_t index;
public:
    ConcreteIterator(const std::vector<int>& coll) : collection(coll), index(0) {}

    bool hasNext() override {
        return index < collection.size();
    }

    int next() override {
        return hasNext() ? collection[index++] : -1; // Return element and move to the next
    }
};

// Define an Aggregate Interface
class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
    virtual ~Aggregate() {}
};

// Implement a Concrete Aggregate
class ConcreteAggregate : public Aggregate {
private:
    std::vector<int> collection;
public:
    ConcreteAggregate(std::initializer_list<int> values) : collection(values) {}

    Iterator* createIterator() override {
        return new ConcreteIterator(collection);
    }
};

// Client Code
int main() {
    // Create a collection (Concrete Aggregate)
    ConcreteAggregate aggregate = { 1, 2, 3, 4, 5 };

    // Create an iterator for the collection
    Iterator* iterator = aggregate.createIterator();

    // Use the iterator to traverse the collection
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    // Clean up memory
    delete iterator;
    return 0;
}
