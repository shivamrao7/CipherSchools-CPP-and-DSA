#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void inorder() {
        inorder(root);
        std::cout << std::endl;
    }

private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(Node* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    Node* remove(Node* node, int value) {
        if (!node) return nullptr;
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (!node->left) {
                Node* rightChild = node->right;
                delete node;
                return rightChild;
            }
            if (!node->right) {
                Node* leftChild = node->left;
                delete node;
                return leftChild;
            }
            Node* minLargerNode = findMin(node->right);
            node->data = minLargerNode->data;
            node->right = remove(node->right, minLargerNode->data);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Inorder traversal: ";
    tree.inorder();

    std::cout << "Searching 4: " << (tree.search(4) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 9: " << (tree.search(9) ? "Found" : "Not Found") << std::endl;

    tree.remove(3);
    std::cout << "Inorder traversal after deleting 3: ";
    tree.inorder();

    return 0;
}
