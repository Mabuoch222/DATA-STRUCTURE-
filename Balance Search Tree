#include <iostream>

// Node structure representing each element in the AVL tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    // Get the height of a node
    int getHeight(Node* node) {
        return (node != nullptr) ? node->height : 0;
    }

    // Update the height of a node based on the heights of its children
    void updateHeight(Node* node) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    // Get the balance factor of a node (height difference between left and right subtrees)
    int getBalanceFactor(Node* node) {
        return (node != nullptr) ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Rotate a subtree to the left (right rotation)
    Node* rotateLeft(Node* y) {
        Node* x = y->right;
        Node* T2 = x->left;

        // Perform rotation
        x->left = y;
        y->right = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Rotate a subtree to the right (left rotation)
    Node* rotateRight(Node* x) {
        Node* y = x->left;
        Node* T2 = y->right;

        // Perform rotation
        y->right = x;
        x->left = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Balance a subtree rooted at the given node
    Node* balance(Node* node) {
        // Update height of the current node
        updateHeight(node);

        // Get the balance factor
        int balanceFactor = getBalanceFactor(node);

        // Left Heavy (Left-Left Case)
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

        // Right Heavy (Right-Right Case)
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

        // Left Right Heavy (Left-Right Case)
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Heavy (Right-Left Case)
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node; // No rotation needed
    }

    // Insert a node into the AVL tree
    Node* insert(Node* node, int value) {
        // Perform standard BST insert
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            // Duplicate values are not allowed
            return node;
        }

        // Balance the current node
        return balance(node);
    }

    // Find the node with the minimum value in the AVL tree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Delete a node from the AVL tree
    Node* deleteNode(Node* node, int value) {
        // Perform standard BST delete
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node found, perform deletion
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = (node->left != nullptr) ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                // Node with two children, get the inorder successor (smallest in the right subtree)
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        // If the tree had only one node, return
        if (node == nullptr) {
            return node;
        }

        // Balance the current node
        return balance(node);
    }

    // In-order traversal of the AVL tree
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Destructor to free memory
    ~AVLTree() {
        // Delete all nodes using in-order traversal
        while (root != nullptr) {
            root = deleteNode(root, root->data);
        }
    }

    // Insert a value into the AVL tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Delete a value from the AVL tree
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Search for a value in the AVL tree
    bool search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true; // Value found
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false; // Value not found
    }

    // Display the AVL tree using in-order traversal
    void display() {
        std::cout << "In-order Traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avlTree;

    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(40);
    avlTree.insert(10);
    avlTree.insert(25);

    std::cout << "Initial AVL Tree:" << std::endl;
    avlTree.display();

    avlTree.remove(20);

    std::cout << "AVL Tree after removing 20:" << std::endl;
    avlTree.display();

    return 0;
}
