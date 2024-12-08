#include <iostream>

using namespace std;

struct Node{
    int data;

    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;    
    }
};

void forwardTreverse(Node* head){
    Node* current = head;

    while(current != nullptr)
    {
        cout << current->data;
        current = current->next;

        if(current != nullptr)
        {
            cout<<" -> ";
        } 
    }
    cout<<endl;
}

void backwardTreverse(Node* tail){
    Node* current = tail;

    while(current != nullptr)
    {
        cout<<current->data;
        current = current->prev;

        if(current != nullptr)
        {
            cout<<" -> "; 
        }
    }
    cout<<endl;
}

int findLenght(Node* head){
    Node* current = head;

    int lenght = 0;

    while(current != nullptr)
    {
        lenght++;
        current = current->next;
    }
    return lenght;
}

Node* insertAtBeginning(Node* head, int value){
    Node* newNode = new Node(value);

    newNode->next = head;
    if(head != nullptr)
        head->prev = newNode;
    
    head = newNode;

    return head;
}

Node* insertAtEnd(Node* head, int value){
    Node* newNode = new Node(value);

    if(head == nullptr)
    {
        head =newNode;
    }
    else{
        Node* current = head;
        while(current->next != nullptr)
        {
            current = current ->next;
        }  

        newNode->prev = current;
        current->next = newNode;
    }
    return head;
}

Node* insertAtPosition(Node* head, int pos, int value){
    Node* newNode = new Node(value);

    if(pos == 1)
    {
        newNode->next = head;
        
        if(head != nullptr)
            head->prev = newNode;
        
        head = newNode;
        return head;
    }

    Node* prev = head;
    for(int i = 1; i < pos - 1 && prev != nullptr; i++)
    {
        prev = prev->next;
    }
    
    if (prev == nullptr) 
    {
        cout << "Position is out of bounds." << endl;
        delete newNode;
        return head;
    }

    newNode->prev = prev;
    newNode->next = prev->next;
    prev->next = newNode;

    //if the newNode isnt the last node update the prev of the next node
    if(newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
    return head;
}

Node* deleteFirstNode(Node* head){
    if(head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;

    if(head != nullptr)
        head->prev = nullptr;

    delete temp;
    return head; 
}

Node* deleteLastNode(Node* head){
    if(head == nullptr) 
        return nullptr;
    
    if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node* current = head;
    while( current->next != nullptr)
        current = current ->next;

    current->prev->next = nullptr;

    delete current;
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    Node* current = head;

    if (head == nullptr)
        return head;

    for (int i = 1; i < pos && current != nullptr; ++i) {
        current = current->next;
    }

    if (pos < 1 || current == nullptr) {
        cout << "Position Out Of Bounds \n";
        return head;
    }

    if (current->prev)
        current->prev->next = current->next;

    if (current->next)
        current->next->prev = current->prev;

    if (head == current)
        head = current->next;

    delete current;
    return head;
}
int main() {

    // Create a hardcoded doubly linked list:
    // 1 <-> 2 <-> 3
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->prev = head1;
    head1->next->next = new Node(3);
    head1->next->next->prev = head1->next;
    head1->next->next->next = new Node(4);
    head1->next->next->next->prev =  head1->next->next;
    
    //deletion of the first node and forward treversing
    cout<<"Original Linked List: ";
    forwardTreverse(head1);
    cout<<"After Deletion at the beginning: ";
    head1 = deleteFirstNode(head1);
    forwardTreverse(head1);

    //deleteing at position
    head1 = deleteAtPosition(head1,3);
    forwardTreverse(head1);
  

    //deleting at the end
    head1 = deleteLastNode(head1);
    forwardTreverse(head1);

    //inserting a  new data at the beginning
    head1 = insertAtBeginning(head1, 10);
    forwardTreverse(head1);

    //inserting a new data at given position
    head1 = insertAtPosition(head1, 2 , 20);
    forwardTreverse(head1);

    //inserting a new data at the end
    head1 = insertAtEnd(head1, 100);
    forwardTreverse(head1);

    //the lenght of  doubly linkedList
    cout << "Count of nodes is " << findLenght(head1)<<endl;

    //backward treversing
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Backward Traversal: ";
    backwardTreverse(third);
}