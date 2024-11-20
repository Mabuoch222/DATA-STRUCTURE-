#include <iostream>

class CircularQueue {
private:
    static const int MAX_SIZE = 5; // Adjust the size based on your requirements
    int* array;
    int front;
    int rear;

public:
    // Constructor
    CircularQueue() : array(new int[MAX_SIZE]), front(-1), rear(-1) {}

    // Destructor to free memory
    ~CircularQueue() {
        delete[] array;
    }

    // Enqueue operation to add an element to the rear of the queue
    void enqueue(int value) {
        if ((rear + 1) % MAX_SIZE == front) {
            std::cerr << "Queue overflow! Cannot enqueue onto a full queue." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        array[rear] = value;
        std::cout << "Enqueued " << value << " into the queue." << std::endl;
    }

    // Dequeue operation to remove and return the element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue underflow! Cannot dequeue from an empty queue." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }

        int dequeuedValue = array[front];

        if (front == rear) {
            // Last element in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
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

        return array[front];
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == -1 && rear == -1;
    }

    // Check if the queue is full
    bool isFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }
};

int main() {
    CircularQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);

    std::cout << "Front of the queue: " << myQueue.peek() << std::endl;

    myQueue.dequeue();
    myQueue.dequeue();

    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    myQueue.dequeue(); // Attempting to dequeue from an empty queue

    return 0;
}
