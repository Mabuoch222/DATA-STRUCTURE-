#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100; // Adjust the size based on your requirements
    int array[MAX_SIZE];
    int top;

public:
    // Constructor
    Stack() : top(-1) {}

    // Push operation to add an element to the top of the stack
    void push(int value) {
        if (top < MAX_SIZE - 1) {
            array[++top] = value;
            std::cout << "Pushed " << value << " onto the stack." << std::endl;
        } else {
            std::cerr << "Stack overflow! Cannot push onto a full stack." << std::endl;
        }
    }

    // Pop operation to remove and return the element from the top of the stack
    int pop() {
        if (top >= 0) {
            int poppedValue = array[top--];
            std::cout << "Popped " << poppedValue << " from the stack." << std::endl;
            return poppedValue;
        } else {
            std::cerr << "Stack underflow! Cannot pop from an empty stack." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }
    }

    // Peek operation to return the element at the top of the stack without removing it
    int peek() const {
        if (top >= 0) {
            return array[top];
        } else {
            std::cerr << "Stack is empty. Cannot peek." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top of the stack: " << myStack.peek() << std::endl;

    myStack.pop();
    myStack.pop();

    std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    myStack.pop(); // Attempting to pop from an empty stack

    return 0;
}
