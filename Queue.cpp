#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;    
    }
};

class Queue{
    Node* front;
    Node* rear;

    public:
        Queue(){this->front = nullptr; this->rear = nullptr;}

    bool isEmpthy()
    {
        return front == nullptr;
    }

    void enqueue(int data)
    {
        Node* temp = new Node(data);

        if(this->isEmpthy())
        {
            front = temp;
            rear = front; 

            return ;
        }else{
            rear -> next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if(this->isEmpthy())
        {   
            cout<<"Queue underflow\n";
            return ;
        }else{
            Node* temp = front;
            front = front -> next;
            if(front == nullptr)
                rear = nullptr;
            delete temp;
        }
    }

    int getFront()
    {
        if(this->isEmpthy())
        {
            cout<<"The queue is empthy\n";
            return 0;
        }else{
            return front->data;
        }
    }

    int getRear()
    {
        if(this->isEmpthy())
        {
            cout<<"The queue is empthy\n";
            return 0;
        }else{  
            return rear->data;
        }
    }

    void printQueue()
    {
        Node* current = front;
        while(current!= nullptr)
        {
            cout<<current->data<<" ";
            current = current -> next;
        }
        cout<<endl<<endl;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<<"Queue:\n";
    q.printQueue();
    cout<<endl;

    cout<<"Queue front: ";
    cout<<q.getFront()<<endl;

    cout<<"Queue rear: ";
    cout<<q.getRear()<<endl;
    cout<<endl;

    cout<<"Queue after enqueue:\n";
    q.enqueue(100);
    q.printQueue();
    
    
    cout<<"Queue after dequeue:\n";
    q.dequeue();
    q.printQueue();

    if(q.isEmpthy())
    {
        cout<<"The queue is empthy\n";
    }else{
        cout<<"The queue isn't empthy\n";
    }
}