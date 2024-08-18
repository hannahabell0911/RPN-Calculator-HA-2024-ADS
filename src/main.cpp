#include "RPNCalculator.h"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
//RPNCalculator Interface- inspiration + help found here https://gist.github.com/dvtate/19d1b67bd454073bf8c7d70b3e3cc79e + ChatGPT
bool isNumber(const std::string& input) {
    return std::regex_match(input, std::regex(R"(^-?\d+(\.\d+)?$)")); // https://stackoverflow.com/questions/12643009/regular-expression-for-floating-point-numbers
}
//https://gist.github.com/dvtate/19d1b67bd454073bf8c7d70b3e3cc79e
int main() {
    RPNCalculator<double> calculator;
    std::string input;
    std::cout << "RPN Calculator. Type 'help' for commands. Enter 'q' to quit.\n";

    while (true) {
        std::cout << "Enter command or value: ";
        std::cin >> input;

        if (input == "q") {
            break;
        } else if (input == "help") {
            std::cout << "Commands:\n"
                      << "+, -, *, / for operations\n"
                      << "s to square, n to negate, p to pop, c to clear\n"
                      << "Type a number to push it onto the stack\n"
                      << "Type q to quit\n";
        } else if (isNumber(input)) {
            calculator.push(std::stod(input));
            std::cout << input << " pushed to stack.\n";
        } else {
            if (calculator.isEmpty() && input != "c") {
                std::cout << "Error: No operands available.\n";
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
                    continue;
                } else if (input == "p") {
                    double poppedValue = calculator.pop();
                    std::cout << "Popped " << poppedValue << " from stack.\n";
                    continue;
                } else {
                    std::cout << "Invalid command. Type 'help' for a list of commands.\n";
                    continue;
                }
                std::cout << "Top of stack: " << calculator.top() << "\n";
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }

    return 0;
}