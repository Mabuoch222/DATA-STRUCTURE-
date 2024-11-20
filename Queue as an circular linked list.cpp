#include <iostream>

// Node structure representing each element in the circular linked list
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear; // Pointer to the rear of the circular linked list

public:
    // Constructor
    CircularQueue() : rear(nullptr) {}

    // Destructor to free memory
    ~CircularQueue() {
        if (!isEmpty()) {
            Node* current = rear->next;
            while (current != rear) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete rear; // Delete the last node (rear)
        }
    }

    // Enqueue operation to add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear; // Circular reference
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued " << value << " into the queue." << std::endl;
    }

    // Dequeue operation to remove and return the element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue underflow! Cannot dequeue from an empty queue." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }

        int dequeuedValue;
        if (rear->next == rear) {
            // Only one element in the queue
            dequeuedValue = rear->data;
            delete rear;
            rear = nullptr;
        } else {
            Node* front = rear->next;
            dequeuedValue = front->data;
            rear->next = front->next;
            delete front;
        }

        std::cout << "Dequeued " << dequeuedValue << " from the queue." << std::endl;
        return dequeuedValue;
    }

    // Peek operation to return the element at the front of the queue without removing it
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }

        return rear->next->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return rear == nullptr;
    }
};

int main() {
    CircularQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front of the queue: " << myQueue.peek() << std::endl;

    myQueue.dequeue();
    myQueue.dequeue();

    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    myQueue.dequeue(); // Attempting to dequeue from an empty queue

    return 0;
}
