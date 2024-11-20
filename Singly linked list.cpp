#include <iostream>

// Node structure representing each element in the linked list
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // (i) Insert an element x at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // (ii) Insert an element x at ith position
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
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
        current->next = newNode;
    }

    // (iii) Remove an element from the beginning
    void removeFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            std::cerr << "List is empty" << std::endl;
        }
    }

    // (iv) Remove an element from ith position
    void removeFromPosition(int position) {
        if (position < 0 || !head) {
            std::cerr << "Invalid position or list is empty" << std::endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current->next; ++i) {
            current = current->next;
        }

        if (!current->next) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // (v) Search for an element x and return its pointer
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

    // (vi) Concatenate two singly linked lists
    void concatenate(SinglyLinkedList& otherList) {
        if (!head) {
            head = otherList.head;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = otherList.head;
        }
        otherList.head = nullptr; // Avoids deleting nodes from the other list in its destructor
    }

    // Display the linked list
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList myList;
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    std::cout << "Original List: ";
    myList.display();

    myList.insertAtPosition(4, 2);
    myList.removeFromBeginning();
    myList.removeFromPosition(1);

    std::cout << "Modified List: ";
    myList.display();

    SinglyLinkedList otherList;
    otherList.insertAtBeginning(7);
    otherList.insertAtBeginning(6);
    otherList.insertAtBeginning(5);

    std::cout << "Other List: ";
    otherList.display();

    myList.concatenate(otherList);

    std::cout << "Concatenated List: ";
    myList.display();

    return 0;
}
