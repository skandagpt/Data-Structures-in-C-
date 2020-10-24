#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node* front;
struct Node* rear;


class Queue
{
    public:
    Queue(){};
    void enqueue(int );
    void dequeue();
    void display();
};

void Queue ::  enqueue(int item)
{
    struct Node* newNode = new Node;
    if(!newNode)
         cout<<"Overflow"<<endl;
    newNode->data = item;

    if(front  == NULL && rear == NULL)
    {
        newNode->next = NULL;
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->next = NULL;
        rear = newNode;
    }
}
void Queue :: dequeue()
{
    struct Node* temp;
    if(front == NULL)
        cout<<"underflow";
    temp = front;
    front = front->next;
    temp->next = NULL;
    free(temp);
}

void Queue :: display()
{
    struct Node* temp;
    if(front == NULL)
        cout<<"underflow";
    cout<<"the queue contains : "<<endl;
    temp = front;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }   
}

int main()
{
    Queue S;
    char a;
    do
    {
        int x;
        cout<<"Enter the value to enqueue onto Queue :";
        cin>>x;
        S.enqueue(x);
        cout<<"Insert more values(y/n) ?";
        cin>>a;
    }
    while(a == 'y');
    S.display();
    char b;
    do
    {    
    cout<<"Do you want to delete value from Queue?(y/n)";
    cin>>b;
    if(b == 'y')
    S.dequeue();
    }
    while(b == 'y');
    S.display();
    return 0;
}