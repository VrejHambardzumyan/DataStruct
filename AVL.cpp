#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVL {
private:
    Node* root;

    int height(Node* N) {
        return N == nullptr ? 0 : N->height;
    }

    int get_balance(Node* N) {
        return N == nullptr ? 0 : height(N->left) - height(N->right);
    }

    Node* right_rotate(Node* y) {
        Node* x = y->left;
        Node* z = x->right;

        x->right = y;
        y->left = z;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* left_rotate(Node* x) {
        Node* y = x->right;
        Node* z = y->left;  

        y->left = x;
        x->right = z;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, int data) {
        if (node == nullptr)
            return new Node(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data) 
            node->right = insert(node->right, data);
        else
            return node; 

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = get_balance(node);

        // Left Left Case
        if (balance > 1 && data < node->left->data)
            return right_rotate(node);

        // Left Right Case
        if (balance > 1 && data > node->left->data) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        // Right Right Case
        if (balance < -1 && data > node->right->data)
            return left_rotate(node);

        // Right Left Case
        if (balance < -1 && data < node->right->data) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    bool search(Node* node, int data) {
        if (node == nullptr) return false;
        if (data == node->data) return true;

        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    Node* min_value_node(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
    
    Node* delete_node(Node* node, int key) {
        if (node == nullptr)
            return node;
    
        // Standard BST deletion
        if (key < node->data)
            node->left = delete_node(node->left, key);
        else if (key > node->data)
            node->right = delete_node(node->right, key);
        else {
            // Node with one or no child
            if ((node->left == nullptr) || (node->right == nullptr)) {
                Node* temp = node->left ? node->left : node->right;
    
                if (temp == nullptr) {
                    // No child
                    temp = node;
                    node = nullptr;
                } else {
                    // One child
                    *node = *temp; 
                }
    
                delete temp;
            } else {
                // Node with two children: get inorder successor
                Node* temp = min_value_node(node->right);
    
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }
    
        if (node == nullptr)
            return node;
    
        node->height = 1 + max(height(node->left), height(node->right));

        int balance = get_balance(node);

        // LL
        if (balance > 1 && get_balance(node->left) >= 0)
            return right_rotate(node);
    
        // LR
        if (balance > 1 && get_balance(node->left) < 0) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
    
        // RR
        if (balance < -1 && get_balance(node->right) <= 0)
            return left_rotate(node);
    
        // RL
        if (balance < -1 && get_balance(node->right) > 0) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
    
        return node;
    }
    
public:
    AVL() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(int data) {
        return search(root, data);
    }

    void preorder() {
        preorder(root);
    }
    
    void remove(int key) {
        root = delete_node(root, key);
    }
    
};

int main() {
    AVL tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Preorder traversal:\n";
    tree.preorder();

    if (tree.search(50))
        cout << "\nThe data we are searching is in the tree.";
    else
        cout << "\nThe data we are searching is not in the tree.";
    
    tree.remove(40);  // Deleting a node

    cout << "\nPreorder traversal after deleting 40:\n";
    tree.preorder();
    cout << "\n40 has been deleted from the tree.";
}

