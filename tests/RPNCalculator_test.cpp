//
// Created by Hannah Abell on 17/08/2024.
//
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

