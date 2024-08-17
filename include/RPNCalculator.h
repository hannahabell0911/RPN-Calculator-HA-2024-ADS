// RPNCalculator.h
#pragma once
#include "Stack.h"
#include <functional>
#include <fstream>
#include <iostream>
#include <string>

template<typename T>
class RPNCalculator {
private:
    Stack<T> stack;

    void logOperation(const std::string& operation, T operand1, T operand2, T result) {
        std::ofstream logFile("RPN.log", std::ios::app);  // Append mode
        if (!logFile) {
            std::cerr << "Error: Unable to open log file." << std::endl;
            return;
        }
        logFile << operation << " (" << operand1 << ", " << operand2 << ") = " << result << std::endl;
        logFile.close();
    }

public:
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

    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return stack.top();
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
            throw std::runtime_error("Insufficient operands for operation");
        }
        T rhs = stack.pop();
        T lhs = stack.pop();
        T result = op(lhs, rhs);
        stack.push(result);
        logOperation(opSymbol, lhs, rhs, result);
    }
};
