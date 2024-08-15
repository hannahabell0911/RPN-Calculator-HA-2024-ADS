//
// Created by Hannah Abell on 15/08/2024.
//
#include <gtest/gtest.h>
#include "Stack.h"

TEST(StackTest, PushAndPop) {
    Stack<int> stack;
    stack.push(1);
    ASSERT_EQ(stack.pop(), 1);
}