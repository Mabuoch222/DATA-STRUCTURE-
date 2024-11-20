#include <iostream>

// Node structure representing each element in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // (i) Insert an element x at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // (ii) Insert an element x at ith position
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            std::cerr << "Invalid position" << std::endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    // (iii) Insert an element x at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // (iv) Remove an element from the beginning
    void removeFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        } else {
            std::cerr << "List is empty" << std::endl;
        }
    }

    // (v) Remove an element from ith position
    void removeFromPosition(int position) {
        if (position < 0 || !head) {
            std::cerr << "Invalid position or list is empty" << std::endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position && current; ++i) {
            current = current->next;
        }

        if (!current) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    // (vi) Remove an element from the end
    void removeFromEnd() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        } else {
            std::cerr << "List is empty" << std::endl;
        }
    }

    // (vii) Search for an element x and return its pointer
    Node* search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // (viii) Concatenate two doubly linked lists
    void concatenate(DoublyLinkedList& otherList) {
        if (!head) {
            head = otherList.head;
            tail = otherList.tail;
        } else if (otherList.head) {
            tail->next = otherList.head;
            otherList.head->prev = tail;
            tail = otherList.tail;
        }
        otherList.head = otherList.tail = nullptr; // Avoids deleting nodes from the other list in its destructor
    }

    // Display the doubly linked list forward
    void displayForward() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Display the doubly linked list backward
    void displayBackward() const {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    std::cout << "Original List (Forward): ";
    myList.displayForward();

    std::cout << "Original List (Backward): ";
    myList.displayBackward();

    myList.insertAtPosition(4, 2);
    myList.removeFromBeginning();
    myList.removeFromPosition(1);

    std::cout << "Modified List (Forward): ";
    myList.displayForward();

    DoublyLinkedList otherList;
    otherList.insertAtEnd(7);
    otherList.insertAtEnd(6);
    otherList.insertAtEnd(5);

    std::cout << "Other List (Forward): ";
    otherList.displayForward();

    myList.concatenate(otherList);

    std::cout << "Concatenated List (Forward): ";
    myList.displayForward();

    return 0;
}
