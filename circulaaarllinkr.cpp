#include<iostream>
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
struct Node *add(struct Node *last, int data) 
{ 
    if (last != NULL) 
      return last; 
    else
    {   
        Node* temp = new Node(); 
        temp -> data = data; 
        last = temp; 
        last -> next = last; 
        return last;
    } 
} 
  
struct Node *Front(struct Node *last, int data) 
{ 
    if (last == NULL) 
        return add(last, data); 
    else
    {   
        Node* temp = new Node();  
        temp -> data = data; 
        temp -> next = last -> next; 
        last -> next = temp; 
        return last;
    } 
} 
  
struct Node *end(struct Node *last, int data) 
{ 
    if (last == NULL) 
        return add(last, data); 
    else
    {    
        Node* temp = new Node(); 
        temp -> data = data; 
        temp -> next = last -> next; 
        last -> next = temp; 
        last = temp; 
        return last;
    } 
} 
  
struct Node *addloc(struct Node *last, int data, int item) 
{ 
    if (last == NULL) 
        return NULL; 
    else
    {    
        struct Node *temp, *p; 
        p = last -> next; 
        do
        { 
            if (p ->data == item) 
            { 
                Node* temp = new Node();
                temp -> data = data; 
                temp -> next = p -> next; 
                p -> next = temp; 
                if (p == last) 
                    last = temp; 
                return last; 
            } 
            p = p -> next; 
        }  
        while(p != last -> next); 
        cout << item << " not present in the list." << endl; 
        return last;
    } 
  
} 
  
void traverse(struct Node *last) 
{ 
    struct Node *p; 
 
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
  
    p = last -> next; 
    cout<<"The elements in the linked list in order are : "<<endl;
    do
    { 
        cout << p -> data << " "<<endl; 
        p = p -> next; 
  
    } 
    while(p != last->next); 
  
} 
   
int main() 
{ 
    struct Node *last = NULL; 
    int x,y;
    cout<<"Enter the value to add : ";
    cin>>x;
    last = add(last, x); 
    cout<<"Enter the elements to add : ";
    cin>>x;
    last = Front(last, x); 
    cout<<"Enter the elements to add to end of linked list : ";
    cin>>x;
    last = end(last, x); 
    cout<<"Enter the element to add after another element : ";
    cin>>x;
    cout<<"Enter the elemnt after which new element is to be inserted : ";
    cin>>y; 
    last = addloc(last, x, y); 
    traverse(last); 
    return 0; 
} 