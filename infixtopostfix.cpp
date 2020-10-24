#include<iostream>
#include<string>
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

int precedence(char c)
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else return -1; 
} 

void convert(string st)
{
    string final;
    Stack S;
    S.push('(');
    int len = st.length();
    for(int i =0; i<len;i++)
    {
        if((st[i] >= 'a' && st[i] <= 'z')||(st[i] >= 'A' && st[i] <= 'Z')) 
        final+=st[i]; 
        else if(st[i]=='(')
        S.push('(');
        else if(st[i] == ')') 
        { 
            while(top->data != '(') 
            { 
                char c = top->data; 
                S.pop(); 
                final += c; 
            } 
            if(top->data == '(') 
            { 
                char c = top->data; 
                S.pop(); 
            } 
        }
        else
        {
            while(top->data != '(' && precedence(st[i]) <= precedence(top->data)) 
            { 
                char c = top->data; 
                S.pop(); 
                final += c; 
            } 
            S.push(st[i]); 
        }  
    }
    
      
    cout << "The postfix expression is : " <<final << endl; 

}

int main()
{
    string exp;
    cout<<"Enter the expression : ";
    cin>>exp;  
    convert(exp);
    return 0;
}