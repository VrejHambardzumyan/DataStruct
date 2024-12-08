#include <iostream>

using namespace std;

struct  Node
{
    int data;
    int priority;
    
    Node* next;

    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
    
};

class PriorityQueue{
    Node* front;
    Node* rear;

    public:
        PriorityQueue(){this->front = nullptr, this->rear = nullptr;}

        bool isEmpthy()
        {
            return front==nullptr;
        }

        void enqueue(int data, int priority)
        {
            Node* newNode = new Node(data, priority);

            if(front == nullptr || front->priority < priority)
            {
                newNode->next = front;
                front =  newNode;
            }else{
                Node* temp = front;
                while(temp->next != nullptr && temp->next->priority > priority)
                {
                    temp = temp -> next;
                }
                newNode -> next = temp -> next;
                temp -> next = newNode;
            }
        }

        void dequeue()
        {
          
            if(this->isEmpthy())
            {
                cout<<"The queuq is already empthy.\n";
            }else{
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        int peek()
        {
            return front->data;
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
    PriorityQueue PQ;

    PQ.enqueue(1,40);
    PQ.enqueue(2,30);
    PQ.enqueue(3,20);
    PQ.enqueue(4,50);
    
    cout<<"The Queue:\n";
    PQ.printQueue();
    cout<<endl;

    cout<<"The front of queuq:\n";
    cout<<PQ.peek();
    cout<<endl;

    cout<<"The queue after dequeue:\n";
    PQ.dequeue();
    PQ.printQueue();

    cout<<"The queue after enqueue:\n";
    PQ.enqueue(10,10);
    PQ.printQueue();

    if(PQ.isEmpthy())
    {
        cout<<"The Queue is empthy\n";
    }else{
        cout<<"The Queue isn't empthy\n";
    }
    

}