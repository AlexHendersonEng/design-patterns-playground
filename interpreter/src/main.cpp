/*
    Interpreter: Used to define a language's grammar and provide an interpreter to
                 evaluate expressions in the language. It is typically used in scenarios
                 where a language needs to be parsed, such as mathematical expressions,
                 SQL queries, or simple scripting languages.

                 Key components:
                 Abstract Expression (Expression): Interface for interpreting expressions.
                 Terminal Expression: Implements interpretation for specific symbols.
                 Non-Terminal Expression: Handles composite expressions.
                 Context: Contains information that is global to the interpreter.
*/

// Include necessary headers
#include <iostream>
#include <string>
#include <map>

// Abstract Expression - Interface for all expressions
class Expression {
public:
    virtual int interpret(std::map<std::string, int>& context) = 0; // Interpret method
    virtual ~Expression() {}
};

// Terminal Expression - Represents a variable (e.g., "x", "y")
class VariableExpression : public Expression {
private:
    std::string name;
public:
    VariableExpression(std::string name) : name(name) {}
    int interpret(std::map<std::string, int>& context) override {
        return context[name]; // Fetch value from context
    }
};

// Terminal Expression - Represents a constant value (e.g., 5, 10)
class ConstantExpression : public Expression {
private:
    int value;
public:
    ConstantExpression(int value) : value(value) {}
    int interpret(std::map<std::string, int>& context) override {
        return value;
    }
};

// Non-Terminal Expression - Represents addition (e.g., x + y)
class AddExpression : public Expression {
private:
    Expression* left, *right;
public:
    AddExpression(Expression* left, Expression* right) : left(left), right(right) {}
    int interpret(std::map<std::string, int>& context) override {
        return left->interpret(context) + right->interpret(context);
    }
    ~AddExpression() {
        delete left;
        delete right;
    }
};

int main() {
    // Context: variable values
    std::map<std::string, int> context;
    context["x"] = 10;
    context["y"] = 5;

    // Expression: x + y
    Expression* expression = new AddExpression(new VariableExpression("x"), new VariableExpression("y"));

	// Expression: x + 5
	Expression* expression1 = new AddExpression(new VariableExpression("x"), new ConstantExpression(6));

    // Interpret and print results
    std::cout << "Result of expression 'x + y': " << expression->interpret(context) << std::endl; // Output: 15
    std::cout << "Result of expression 'x + 6': " << expression1->interpret(context) << std::endl; // Output: 16

    // Clean up
    delete expression;
    return 0;
}
