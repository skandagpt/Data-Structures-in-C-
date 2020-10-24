#include<iostream>
using namespace std;

class Queue
{
    private:
    int front = 0;
    int rear = 0;
    int *queue;
    public:
    Queue(){
        queue = new int;
    };
    void enqueue();
    void dequeue();
    void display();
};

void Queue :: enqueue()
{
        int item;
        if (front == 0)
            front = 1;
        cout<<"Insert the element in queue : ";
        cin>>item;
        cout<<item<<endl;
        rear++;
        queue[rear] = item; 
}
void Queue :: dequeue()
{
    if (front == 0 || front > rear)
    {
        cout<<"Queue Underflow "<<endl;
    }
    else
    {
        cout<<"Element deleted from queue is : "<<queue[front]<<endl;
        front = front + 1;
    }
}
void Queue :: display()
{
    int i;
    if (front == - 1)
        cout<<"Queue is empty \n";
    else
    {
        cout<<"Queue is : \n";
        for (i = front; i <= rear; i++)
            cout<<queue[i]<<endl;
        cout<<endl;
    }
}
int main()
{
    Queue S;
    char a;
    do
    {
        S.enqueue();
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