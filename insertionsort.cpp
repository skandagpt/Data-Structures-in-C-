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
    for(int i = 1;i<n;i++)
        {
            int k = arr[i];
            int j = i-1;
            while(arr[j]>k && j>=0)
            {
                  arr[j+1]=arr[j];
                  j=j-1;
            }
            arr[j+1]=k;
        }
    cout<<"Sorted array is : "<<endl;
    for(int i =0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}