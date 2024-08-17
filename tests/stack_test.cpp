//
// Created by Hannah Abell on 15/08/2024.
//
#include <gtest/gtest.h>
#include "Stack.h"

class StackTest : public ::testing::Test {
protected:
    Stack<int> stack;
};

TEST_F(StackTest, PushAndPopSingle) {
    stack.push(1);
    ASSERT_EQ(stack.pop(), 1);
}
TEST_F(StackTest, PopFromEmptyStack) {
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_THROW(stack.pop(), std::out_of_range);
}
TEST_F(StackTest, TopElement) {
    stack.push(10);
    stack.push(20);
    ASSERT_EQ(stack.top(), 20);  // Check top element is 20
    stack.pop();
    ASSERT_EQ(stack.top(), 10);  // After popping, check new top is 10
}
TEST_F(StackTest, ClearStack) {
    stack.push(10);
    stack.push(20);
    stack.clear();
    EXPECT_TRUE(stack.isEmpty());  // Check stack is empty
    EXPECT_EQ(stack.size(), 0);    // Check size is 0
}
TEST_F(StackTest, SizeOfStack) {
    EXPECT_EQ(stack.size(), 0);  // Initially, size should be 0
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.size(), 2);  // Size should now be 2
    stack.pop();
    EXPECT_EQ(stack.size(), 1);  // Size should decrease to 1 after pop
}
TEST_F(StackTest, MultiplePushAndPop) {
    stack.push(1);
    stack.push(2);
    stack.push(3);
    ASSERT_EQ(stack.pop(), 3);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.isEmpty());  // Stack should be empty after all pops
}
TEST_F(StackTest, TopFromEmpty) {
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_THROW(stack.top(), std::out_of_range);
}
