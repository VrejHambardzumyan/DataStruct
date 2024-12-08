#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree{
    Node* root;
    
    BinarySearchTree(){this->root = nullptr;}

    void inOrderTrevers(Node* root)
    {
        if(root == nullptr) return;

        inOrderTrevers(root->left);

        cout<<root->data<<" ";

        inOrderTrevers(root->right);

    }

    void preOrderTrevers(Node* root)
    {
        if(root == nullptr) return;

        cout<<root->data<<" ";
        preOrderTrevers(root->left);
        preOrderTrevers(root->right);
    }

    void postOrderTrevers(Node* root)
    {
        if(root == nullptr) return;

        postOrderTrevers(root->left);
        postOrderTrevers(root->right);
        cout<<root->data<<" ";
    }

    Node* insert(Node* node, int data)
    {
        if(node == nullptr) return new Node(data);

        if(node->data == data) return node;

        if(node->data < data)
        {
            node->right = insert(node->right, data);
        }else{
            node->left = insert(node->left, data);
        }
        return node;

    }

    Node* search(Node* root, int data)
    {
        if(root == nullptr || root->data == data) return root;

        if(root->data < data) 
        {
            return search(root->right, data);
        }else{ 
            return search(root->left, data);
        }   
    }

    Node* getSuccessor()
    {
        root = root->right;
        while(root != nullptr && root->left != nullptr)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int data)
    {
        if(root == nullptr)
            return root;
        
        if(root->data > data)
        {
            root->left = deleteNode(root->left,data); 
        }else if (root->data < data){
            root->right = deleteNode(root->right, data);
        }else{
            if(root->right != nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if(root->left != nullptr)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* succ = getSuccessor();
            root->data = succ->data;
            root->right =deleteNode(root->right, succ->data);

        }
        return root;
    }
};
