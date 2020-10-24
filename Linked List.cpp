#include <iostream>
using namespace std;

int flag = 0, n;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head, *ptr, *temp;
void insert(int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    if (flag == 0)
    {
        ptr = head = newNode;
        flag = 1;
    }
    else
    {
        ptr->next = newNode;
        ptr = ptr->next;
    }
}
void insertLoc(int data, int pos)
{
    int c = 1;
    ptr = head;
    if (pos == 1)
    {
        Node* newNode = new Node();
        head = newNode;
        head->next = ptr;
        newNode->data = data;
        c++;
    }
    else
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        
        if (pos == c)
        {
            Node* newNode = new Node();
            temp = ptr->next;
            ptr->next = newNode;
            newNode->next = temp;
            newNode->data = data;
        }
        ptr = ptr->next;
        c++;
    }
    if (pos == n + 1)
    {
        Node* newNode = new Node();
        ptr->next = newNode;
        newNode->next = NULL;
        newNode->data = data;
    }
}
void display()
{
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout<<endl;
}
void deletea(struct Node **headref, int data)
{
    struct Node *temp = *headref, *prev;
    if (temp != NULL && temp->data == data)
    {
        *headref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
int main()
{
    int i = 0, data,  pos;
    cout << "Enter no of elements you want to enter:";
    cin >> n;
    cout  << "Enter elements:" << endl;
    while (i < n)
    {
        cin >> data;
        insert(data);
        i++;
    }
    ptr->next = NULL;
    display();

    cout <<"Adding another element :"<<endl;
	cout << "enter element which you want enter:";
 	cin >> data;
	cout<<"Enter the position to insert element :";
	cin>>pos;
	insertLoc(data, pos);
    display();
    cout << "Enter element to delete:";
    cin >> data;
    deletea(&head,data);
    display();
}