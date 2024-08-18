#include "RPNCalculator.h"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>


bool isNumber(const std::string& input) {
    return std::regex_match(input, std::regex(R"(^-?\d+(\.\d+)?$)")); // Regex for matching numbers
}

int main() {
    RPNCalculator<double> calculator;
    std::string input;

    std::cout << "Hello, my name is Hannah. Welcome to the RPN Calculator.\n"
              << "Type 'help' for a list of commands. Enter 'q' to quit.\n"
              << "Commands: 's' to square, 'n' to negate, 'p' to pop, 'c' to clear\n";

    while (true) {
        std::cout << (calculator.isEmpty() ? "X > " : std::to_string(calculator.top()) + " > ");
        std::cin >> input;

        if (input == "q") {
            break;
        } else if (input == "help") {
            std::cout << "Commands:\n"
                      << "+, -, *, / for basic operations\n"
                      << "s to square, n to negate, p to pop, c to clear\n"
                      << "Type a number to push it onto the stack\n"
                      << "Type 'q' to quit\n";
        } else if (isNumber(input)) {
            calculator.push(std::stod(input));
            std::cout << input << " pushed to stack.\n";
        } else {
            if ((input == "+" || input == "-" || input == "*" || input == "/") && calculator.stackSize() < 2) {
                if (calculator.stackSize() == 1) {
                    calculator.pop();
                    std::cout << "Not enough operands. Stack cleared.\n";
                } else {
                    std::cout << "Error: No operands available for operation.\n";
                }
                continue;
            }

            try {
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
                    std::cout << "Stack cleared.\n";
                } else if (input == "p") {
                    double poppedValue = calculator.pop();
                    std::cout << "Popped " << poppedValue << " from stack.\n";
                } else {
                    std::cout << "Invalid command. Type 'help' for a list of commands.\n";
                }
                if (!calculator.isEmpty()) {
                    std::cout << "Top of stack: " << calculator.top() << "\n";
                } else {
                    std::cout << "Stack is empty.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }

    return 0;
}
