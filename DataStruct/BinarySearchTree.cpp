#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
    Node* root;

public:
    BinarySearchTree() { this->root = nullptr; }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (data < current->data)
                current = current->left;
            else if (data > current->data)
                current = current->right;
            else
                return; // No duplicates in BST
        }

        if (data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    Node* search(int data) {
        Node* current = root;

        while (current != nullptr && current->data != data) {
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return current;
    }

    void inOrder() {
        if (root == nullptr) return;

        stack<Node*> s;
        Node* current = root;

        while (!s.empty() || current != nullptr) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
        cout << endl;
    }

    void preOrder() {
        if (root == nullptr) return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            cout << current->data << " ";

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
        cout << endl;
    }

    void postOrder() {
        if (root == nullptr) return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
        cout << endl;
    }

    void deleteNode(int data) {
        if (root == nullptr) return;

        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr && current->data != data) {
            parent = current;
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current == nullptr) return; // Node not found

        // Case 1: Node with only one child or no child
        if (current->left == nullptr || current->right == nullptr) {
            Node* child = (current->left) ? current->left : current->right;

            if (parent == nullptr) {
                root = child;
            } else if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }

            delete current;
        }
        // Case 2: Node with two children
        else {
            Node* succParent = current;
            Node* successor = current->right;

            while (successor->left != nullptr) {
                succParent = successor;
                successor = successor->left;
            }

            current->data = successor->data;

            if (succParent->left == successor)
                succParent->left = successor->right;
            else
                succParent->right = successor->right;

            delete successor;
        }
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order Traversal: ";
    bst.inOrder();

    cout << "Pre-order Traversal: ";
    bst.preOrder();

    cout << "Post-order Traversal: ";
    bst.postOrder();

    cout << "Search for 40: " << (bst.search(40) != nullptr ? "Found" : "Not Found") << endl;

    cout << "Delete 70\n";
    bst.deleteNode(70);

    cout << "In-order Traversal after deletion: ";
    bst.inOrder();

    return 0;
}
