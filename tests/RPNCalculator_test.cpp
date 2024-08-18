//
// Created by Hannah Abell on 17/08/2024.
//Setting up and tested unit testing by following this tutorial https://www.youtube.com/watch?v=FEFpabSn-Yo and used chatgpt to help me problem solve division by zero test
#include <gtest/gtest.h>
#include "RPNCalculator.h"

template<typename T>
class RPNCalculatorTest : public ::testing::Test {
protected:
    RPNCalculator<T> calculator;
};

using IntCalculatorTest = RPNCalculatorTest<int>;


TEST_F(IntCalculatorTest, HandlesAddition) {
    calculator.push(5);
    calculator.push(3);
    calculator.add();
    EXPECT_EQ(calculator.top(), 8);
}


TEST_F(IntCalculatorTest, HandlesSubtraction) {
    calculator.push(10);
    calculator.push(4);
    calculator.subtract();
    EXPECT_EQ(calculator.top(), 6);
}
TEST_F(IntCalculatorTest, HandlesMultiplication) {
    calculator.push(7);
    calculator.push(6);
    calculator.multiply();
    EXPECT_EQ(calculator.top(), 42);
}

TEST_F(IntCalculatorTest, HandlesDivision) {
    calculator.push(8);
    calculator.push(2);
    calculator.divide();
    EXPECT_EQ(calculator.top(), 4);
}

TEST_F(IntCalculatorTest, HandlesDivisionByZero) {
    calculator.push(10);
    calculator.push(0);

    calculator.divide();

    EXPECT_FALSE(calculator.isEmpty());
    EXPECT_EQ(calculator.top(), 0);
    EXPECT_EQ(calculator.pop(), 0);
    EXPECT_EQ(calculator.pop(), 10);
}

