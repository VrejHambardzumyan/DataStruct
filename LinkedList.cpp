#include <iostream>

using namespace std;

struct Node{
    int data;

    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node* reversedLinkedList(Node *head){
    Node* current = head;
    Node* prev = nullptr;
    
    while(current != nullptr)
    {   
        Node* temp = current -> next;
        current ->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;

    return head;
}


void treverseLinkedList(Node *head){
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;

        if (current != nullptr)
        {
            cout << "-> ";
        }   
    }
    cout << endl;
}

bool searchLinkedList(Node *head, int target){
    Node* current = head; 
    while (head != nullptr)
    {   
        if (current->data == target)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

int findLenght(Node* head){
    int lenght = 0;
    Node* current = head;

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
    head = newNode;

    return head;
}

Node* insertAtEnd(Node* head, int value){
    Node* newNode= new Node(value);
    
    if(head == nullptr)
        return newNode;
    

    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current -> next = newNode;
   
    return head;
}

Node* insertInPosition(Node* head, int pos, int value){
    if(pos < 1)
    {
        cout<< "Invalid Position"<<endl;
        return head;
    }

    if(pos == 1)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        
        return newNode;
    }

    Node* prev = head;
    int count = 1;
    while (count < pos - 1 && prev != nullptr)
    {
        prev = prev->next;
        count++;
    }
    
    if(prev == nullptr)
    {
        cout<<"Position Out Of Bounds "<<endl;
        return head;
    }

    Node* temp = new Node(value);
    temp->next = prev->next;
    prev->next = temp;

    return head;
}

Node* deleteFirstNode(Node* head){
    if(head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;

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

    Node* secondLast = head;
    while(secondLast->next->next != nullptr)
        secondLast = secondLast->next;
    
    delete secondLast->next;

    secondLast->next = nullptr;

    return head;
}

Node* deletAtPosition(Node* head, int pos){
    if(head == nullptr || pos < 1)
        return head;         

    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    Node* current = head;
    for(int i = 1; i < pos - 1 && current != nullptr; i++)
    {
        current = current->next;
    }

    if(current == NULL || current->next == nullptr)
        return 0;

   
    Node* temp = current->next;
    current->next = current->next->next;

    delete temp;
    return head;
}

int main() {
  
    // Create the linked list 2->3->4->5
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);


    //inserting at beginning
    int data = 1;
    head = insertAtBeginning(head, data);
    treverseLinkedList(head);

    //searching value in the list
    int key = 4;
    if(searchLinkedList(head, key))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    //the lenght of  linkList
    cout << "Count of nodes is " << findLenght(head)<<endl;

    //inserting at end
    int data2 = 9;
    head = insertAtEnd(head, data2);
    treverseLinkedList(head);

    //inserting at position
    int pos = 3;
    int data3 = 6;
    head = insertInPosition(head, pos, data3);
    treverseLinkedList(head);

    //deleteing at beginning
    head = deleteFirstNode(head);
    treverseLinkedList(head);

    //deleteing at end
    head = deleteLastNode(head);
    treverseLinkedList(head);

    //deleteing at position
    int pos2 = 4;
    head = deletAtPosition(head, pos2);
    treverseLinkedList(head);

    //reverse linkedList
    head = reversedLinkedList(head);
    treverseLinkedList(head);
}