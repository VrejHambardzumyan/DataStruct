#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

int height(Node *N)
{
    if(N == nullptr)
        return 0;

    return N->height;
}

Node *right_rotate(Node *y)
{
    Node *x = y->left;
    Node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = 1 + max(height(y->left),height(y->right));
    x->height = 1 + max(height(x->left),height(x->right));
    return x;
}

Node *left_rotate(Node *x)
{
    Node *y = x->right;
    Node *z = y->left;

    y->left = x;
    x->right = z;

    y->height = 1 + max(height(y->left),height(y->right));
    x->height = 1 + max(height(x->left),height(x->right));
    return y;
}

int get_balance(Node *N)
{
    if(N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int data)
{
    if(node == nullptr)
        return new Node(data);
    
    if(data < node->data)
        node->left = insert (node->left, data);
    else if(data > node->data)
        node->right = insert (node->right, data);
    else
        return node;

    node->height = 1 + max (height(node->left), height(node->right));

    int balance = get_balance(node);

    //left left
    if(balance > 1 && data < node->left->data)
        return right_rotate(node);
    
    //left right  
    if(balance > 1 && data > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }   

    //right right
    if(balance < -1 && data > node->right->data)
        return left_rotate(node);
    
    //right left    
    if(balance > 1 && data < node->right->data)
    {
        node->right = left_rotate(node->right);
        return right_rotate(node);
    }

    return node;
}


bool search(Node *root,int data)
{
    if(root == nullptr) return false;
    if(data == root->data) return true;


    if(data > root->data)
        search(root->right, data);
    else 
        search(root->left, data);
}

Node* preorder(Node *root)
{
    if(root!=nullptr)
    {
        cout<<root->data<<" ";

        preorder(root->left);
        preorder(root->right);
    
    }
        
}
// Driver Code 
int main() { 
    Node *root = nullptr; 
    
    // Constructing tree given in the above figure 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    
    /* The constructed AVL Tree would be 
              30 
            /   \ 
          20     40 
         /  \      \ 
       10   25     50 
    */
    cout << "Preorder traversal : \n"; 
    preorder(root); 

    if(search(root,50))
        cout<<"\nThe data we are searching is in the tree";
    else
        cout<<"\nThe data we are searching is not in the tree";
} 
