//
// Created by Hannah Abell on 31/07/2024.
//

#ifndef RPNCALCULATOR_HA_2024_STACK_H
#define RPNCALCULATOR_HA_2024_STACK_H

#endif //RPNCALCULATOR_HA_2024_STACK_H
// Stack.h
#pragma once

#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    // Constructor (if needed)
    Stack() {}

    // Push an element onto the stack
    void push(const T& element) {
        elements.push_back(element);
    }

    // Remove and return the top element of the stack
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    // Get the top element of the stack
    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Clear the stack
    void clear() {
        elements.clear();
    }

    // Optional: Size of the stack
    size_t size() const {
        return elements.size();
    }
};
