// RPNCalculator.h
#pragma once
#include "Stack.h"
#include <functional>
#include <fstream>
#include <iostream>
#include <string>
// for info on logging https://www.geeksforgeeks.org/logging-system-in-cpp/ accessed 14th August 2024
// for help with functions I found this helpful video https://www.youtube.com/watch?v=zla7ha0OORM watched 14th August 2024
template<typename T>
class RPNCalculator {
private:
    Stack<T> stack;

    void logOperation(const std::string& operation, T operand1, T operand2, T result) {
        std::ofstream logFile("RPN.log", std::ios::app);  // Append mode for logging operations
        if (!logFile) {
            std::cerr << "Error: Unable to open log file." << std::endl;
            return;
        }
        logFile << operation << " (" << operand1 << ", " << operand2 << ") = " << result << std::endl;
        logFile.close();
    }

    void logError(const std::string& errorMsg) {
        std::ofstream logFile("RPN.log", std::ios::app);  // Append mode for logging errors
        if (!logFile) {
            std::cerr << "Error: Unable to open log file." << std::endl;
            return;
        }
        logFile << errorMsg << std::endl;
        logFile.close();
    }

public:

    size_t stackSize() const {
        return stack.size();
    }

    void push(T value) {
        stack.push(value);
    }

    void add() {
        performOperation(std::plus<T>(), "+");
    }

    void subtract() {
        performOperation(std::minus<T>(), "-");
    }

    void multiply() {
        performOperation(std::multiplies<T>(), "*");
    }

    void divide() {
        performOperation(std::divides<T>(), "/");
    }

    void square() {
        if (stack.isEmpty()) {
            logError("Not enough operands.");
            std::cout << "Not enough operands." << std::endl;
            return;
        }

        T value = stack.pop();
        T result = value * value;
        stack.push(result);
        logOperation("square", value, value, result);
    }

    void negate() {
        if (stack.isEmpty()) {
            logError("Not enough operands.");
            std::cout << "Not enough operands." << std::endl;
            return;
        }
        T value = stack.pop();
        T result = value * -1;
        stack.push(result);
        logOperation("negate", value, value, result);
    }

    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return stack.top();
    }

    T pop() {
        if (stack.isEmpty()) {
            logError("Not enough operands.");
            std::cout << "Not enough operands." << std::endl;
            return T();
        }

        T top = stack.top();
        stack.pop();
        return top;
    }

    void clear() {
        stack.clear();
    }

    bool isEmpty() const {
        return stack.isEmpty();
    }

private:
    template<typename Op>
    void performOperation(Op op, const std::string& opSymbol) {
        if (stack.size() < 2) {
            logError("Insufficient operands for operation " + opSymbol);
            std::cout << "Insufficient operands for operation " + opSymbol << std::endl;
            return;
        }
        T rhs = stack.pop();
        T lhs = stack.pop();

        if (opSymbol == "/" && rhs == 0) {
            logError("Attempt to divide by zero.");
            std::cout << "Attempt to divide by zero." << std::endl;
            stack.push(lhs);
            stack.push(rhs);
            return;
        }

        T result = op(lhs, rhs);
        stack.push(result);
        logOperation(opSymbol, lhs, rhs, result);
    }
};
