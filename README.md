# RPN-Calculator-HA-2024-ADS
My ADS repeat assignment
Completed by Hannah Abell, student number: D00249620

## Project Introduction
The RPNCalculator is a Reverse Polish Notation (RPN) calculator implemented in C++, that utilizes a stack-based approach to perform arithmetic operations. This project was designed to demonstrate an ability in applying advanced C++ techniques, including templates, exception handling, and unit testing.

## Features
- **Arithmetic Operations**: This project supports addition, subtraction, multiplication, division, squaring, and negation.
- **Error Handling**: Contains error management to handle division by zero and any stack underflow.
- **Interactive CLI**: A Command-line interface for real-time calculation.
- **Logging**: Detailed operation and error logging to `RPN.log`.

## To use this project
1. **Clone the repository**: https://github.com/hannahabell0911/RPN-Calculator-HA-2024-ADS
2. **Compile the project** (make sure you have a C++ compiler installed): cd RPNCalculator g++ -o RPNCalculator main.cpp RPNCalculator.h Stack.h -std=c++11
3. **Run the calculator**: ./RPNCalculator
   
## Usage
After running the calculator, you will be prompted to enter commands or numbers. Here is how you can use it:
- To perform operations: Enter the numbers followed by the operation symbol (`+`, `-`, `*`, `/`). For example, to add 10 and 20, input: 10 20 +
- To square a number: Enter the number followed by `s`.
- To negate a number: Enter the number followed by `n`.
- To clear the stack: Enter `c`.
- To quit the program: Enter `q`.

## Testing
This project uses Google Test for unit testing. To run the tests, compile the test suite and execute.

## Acknowledgments & References
- For info on logging: https://www.geeksforgeeks.org/logging-system-in-cpp/ accessed 14th August 2024
- For help with functions I found this helpful video: https://www.youtube.com/watch?v=zla7ha0OORM watched 14th August 2024
- This Stack implementation is inspired by an example found on the site GeeksforGeeks. https://www.geeksforgeeks.org/stack-data-structure-introduction-program/ accessed June 11th, 2024
- Setting up and tested unit testing by following this tutorial: https://www.youtube.com/watch?v=FEFpabSn-Yo watched August 11th 2024
- Chatgpt used for help problem solving errors easily.
- RPNCalculator Interface- inspiration + help found here https://gist.github.com/dvtate/19d1b67bd454073bf8c7d70b3e3cc79e 



