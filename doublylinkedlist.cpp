#include <iostream>  
using namespace std;
struct Node 
{  
    int data;  
    struct Node* next;  
    struct Node* prev;  
};  
  
void push(struct Node** head, int data)  
{  
    Node* temp = new Node();  
  
    temp->data = data;  
  
    temp->next = (*head);  
    temp->prev = NULL;  
  
    if ((*head) != NULL)  
        (*head)->prev = temp;  
  
    (*head) = temp;  
}  

void print(struct Node* node)  
{  
    struct Node* last;  
    cout<<"Traversal in forward direction "<<endl;  
    while (node != NULL) 
    {  
        cout<< node->data<<endl;  
        last = node;  
        node = node->next;  
    }  
    cout<<endl;
    cout<<"Traversal in reverse direction "<<endl;  
    while (last != NULL) 
    {  
        cout<<last->data<<endl;  
        last = last->prev;  
    }  
}  
int main()  
{  
    struct Node* head = NULL; 
    int x;
    for(int i = 0 ; i<5; i++)
    {
        cout<<"Enter the value to add to linked list : ";
        cin>>x;
        push(&head , x);
    }  
    cout<<"Created Linked List is: "<<endl;  
    print(head);  
    return 0;  
}  
