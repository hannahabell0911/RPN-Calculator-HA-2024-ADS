// RPNCalculator.h
#pragma once
#include "Stack.h"

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
        return stack.top();
    }

    bool isEmpty() const {
        return stack.isEmpty();
    }

private:
    template<typename Op>
    void performOperation(Op op) {
        T rhs = stack.pop();
        T lhs = stack.pop();
        stack.push(op(lhs, rhs));
    }
};
