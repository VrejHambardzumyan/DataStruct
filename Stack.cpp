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

class Stack{
    Node* head;

    public:
        Stack(){this->head = nullptr;}

        bool isEmpty(){ 
            return head==nullptr;
        }

        void push(int data){
            Node* newNode = new Node(data);

            if(!newNode)
            {
                cout<<"Stack overflow\n";
            }

            newNode->next = head;
            head = newNode;    
        }

        void pop(){
            if(head == nullptr)
            {
                cout<<"Stack underflow\n";
            }else{
                Node* temp = head;
                head = head->next;
                
                delete temp;
            }
        }

        int peek(){
            if(head == nullptr)
            {
                cout<<"The stack is empthy\n";
                return 0;
            }else{
                return head->data;
            }
        }

        void printStack()
        {
            Node* current = head;
            while(current != nullptr)
            {
                cout<<current->data<<endl;
                current = current -> next;
            }
            cout<<endl; 
        }
};

int main(){
    Stack st;

    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"The stack is:\n";
    st.printStack();

    cout<<"The stack after pop function\n";
    st.pop();
    st.printStack();

    if(st.isEmpty())
    {
        cout<<"The stack is empthy\n";
    }else{
        cout<<"The stack isn't empthy\n";
    }

    cout<<"The  top element of the stack is: "<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.pop();
}