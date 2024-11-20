#include <iostream>
#include <stack>
#include <sstream>
#include <cmath> // For pow function

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                std::cerr << "Error: Division by zero." << std::endl;
                exit(1);
            }
        case '^':
            return static_cast<int>(std::pow(operand1, operand2));
        default:
            std::cerr << "Error: Invalid operator." << std::endl;
            exit(1);
    }
}

int evaluatePostfix(const std::string& postfixExpression) {
    std::stack<int> operandStack;

    std::istringstream iss(postfixExpression);
    std::string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            // If the token is an operand (numeric value), push it onto the stack
            operandStack.push(std::stoi(token));
        } else if (isOperator(token[0])) {
            // If the token is an operator, pop operands from the stack, perform the operation,
            // and push the result back onto the stack
            if (operandStack.size() < 2) {
                std::cerr << "Error: Insufficient operands for operator " << token << std::endl;
                exit(1);
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = performOperation(token[0], operand1, operand2);
            operandStack.push(result);
        } else {
            std::cerr << "Error: Invalid token in the expression." << std::endl;
            exit(1);
        }
    }

    // The final result should be at the top of the stack
    if (operandStack.size() == 1) {
        return operandStack.top();
    } else {
        std::cerr << "Error: Invalid expression." << std::endl;
        exit(1);
    }
}

int main() {
    std::string postfixExpression;
    std::cout << "Enter a postfix expression (operands and operators separated by spaces): ";
    std::getline(std::cin, postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
