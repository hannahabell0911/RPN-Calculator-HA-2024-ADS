#include "RPNCalculator.h"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>

bool isNumber(const std::string& input) {
    return std::regex_match(input, std::regex(R"(^-?\d+(\.\d+)?$)")); // https://stackoverflow.com/questions/12643009/regular-expression-for-floating-point-numbers
}
int main() {
    RPNCalculator<double> calculator;
    std::string input;
    std::cout << "RPN Calculator. Enter 'q' to exit.\n";

    while (true) {
        std::cout << "Enter command or value: ";
        std::cin >> input;

        if (input == "q") {
            break;
        } else if (isNumber(input)) {
            calculator.push(std::stod(input));
        } else {
            if (input == "+") {
                calculator.add();
            } else if (input == "-") {
                calculator.subtract();
            } else if (input == "*") {
                calculator.multiply();
            } else if (input == "/") {
                calculator.divide();
            } else if (input == "s") {
                calculator.square();
            } else if (input == "n") {
                calculator.negate();
            } else if (input == "c") {
                calculator.clear();
            } else if (input == "p") {
                calculator.pop();
            } else {
                std::cout << "Invalid command.\n";
            }
        }

        if (!calculator.isEmpty()) {
            std::cout << "Top of stack: " << calculator.top() << "\n";
        } else {
            std::cout << "Stack is empty.\n";
        }
    }

    return 0;
}