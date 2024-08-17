#include <iostream>
#include <string>
#include "../include/RPNCalculator.h"

int main() {
    RPNCalculator<double> calculator;

    calculator.push(5);
    calculator.push(3);

    calculator.add();

    std::cout << "Result of 5 + 3: " << calculator.top() << std::endl;

    calculator.push(2);
    calculator.multiply();  // (5 + 3) * 2

    std::cout << "Final result (8 * 2): " << calculator.top() << std::endl;

    std::cout << "Is the calculator empty? " << (calculator.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
