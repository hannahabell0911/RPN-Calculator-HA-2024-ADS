// RPNCalculator.h
#pragma once
#include "Stack.h"
#include <functional>

template<typename T>
class RPNCalculator {
private:
    Stack<T> stack;

public:
    void push(T value) {
        stack.push(value);
    }

    void add() {
        performOperation(std::plus<T>());
    }

    void subtract() {
        performOperation(std::minus<T>());
    }

    void multiply() {
        performOperation(std::multiplies<T>());
    }

    void divide() {
        performOperation(std::divides<T>());
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
    void performOperation(Op op) {
        if (stack.size() < 2) {
            throw std::runtime_error("Insufficient operands");
        }
        T rhs = stack.pop();
        T lhs = stack.pop();
        stack.push(op(lhs, rhs));
    }

};
