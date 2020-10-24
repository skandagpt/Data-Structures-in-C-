#include<iostream>
using namespace std;

int main()
{
    int n ,temp;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    for(int i =0 ; i<n-1;i++)
    {
       int min = i;
       for(int j=i;j<n;j++)
       {
            if(arr[min]>arr[j])
                min = j;
       }
       int temp = arr[min];
       arr[min]=arr[i];
       arr[i]=temp;
    }
    cout<<"sorted array is : "<<endl;
    for(int i =0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
