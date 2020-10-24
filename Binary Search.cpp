#include<iostream>
using namespace std;

void display(int *arr , int n)
{
	for(int i = 0 ; i<n ; i++)
		cout<<arr[i]<<endl;
}
int binarySearch(int *arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void deletea(int *arr, int x, int j)
{ 
    int k;
    k=x;    
    if(j <= x)
   {
        for(k=j;k<x-1;k++)
       {
             arr[k]=arr[k+1];
        }
    }
    x=x-1;
    cout<<"The new array is: "<<endl;
    display(arr,x);
}
void insert(int *a, int n, int item)
{
    int k,j;
    cout<<"Enter the index to enter the element: "<<endl;
    cin>>j;
    k=n;
    if(j<=n)
    {
	    while(k>=j)
	    {
	        a[k+1]=a[k];
	        k=k-1;
	    }
	    a[j]=item;
	    n=n+1;
	    cout<<"The new array is: "<<endl;
	    display(a , n);
    }
    else
        cout<<"The index does not exist in the given array."<<endl;
}

int main()
{
    int n ,i , item ;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int arr[n+1];
    cout<<"Enter the elements in sorted manner : "<<endl;
    for(i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element you wish to search: "<<endl;
    cin>>item;
    int x = binarySearch(arr,0,n-1,item);
    cout<<"The value is found at position "<<x+1<<endl;
    if(x!=-1)
    {
   		deletea(arr,n,x);
    }
    else
    {
	   	insert(arr,n,item);
    }
    return 0;
}