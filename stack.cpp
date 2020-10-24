#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
struct node* top;

class Stack
{
    public:
    Stack(){};
    void push(int );
    void pop();
    void display();
};

void Stack ::  push(int item)
{
    struct node* newNode = new node;
    if(!newNode)
         cout<<"Stack Overflow"<<endl;
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

void Stack :: pop()
{
    struct node* temp;
    if(top == NULL)
        cout<<"underflow";
    temp = top;
    top = top->next;
    temp->next = NULL;
    free(temp);
}

void Stack :: display()
{
    struct node* temp;
    if(top == NULL)
        cout<<"underflow";
    cout<<"the stack contains : "<<endl;
    temp = top;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }   
}

int main()
{
    Stack S;
    char a;
    do
    {
        int x;
        cout<<"Enter the value to push onto Stack :";
        cin>>x;
        S.push(x);
        cout<<"Insert more values(y/n) ?";
        cin>>a;
    }
    while(a == 'y');
    S.display();
    char b;int 
    do
    {    
    cout<<"Do you want to delete value from Stack?(y/n)";
    cin>>b;
    if(b == 'y')
    S.pop();
    }
    while(b == 'y');
    S.display();
    return 0;
}