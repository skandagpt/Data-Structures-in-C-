#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    int n ,temp;
    clock_t start1,end1;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++)
        arr[i]=rand()%100;
    int t=0;
    start1 = clock();
    while(t<n)
    {
        for(int i = 0 ; i<n-t-1;i++){
            if(arr[i]>arr[i+1])
            {
                 temp = arr[i];
                 arr[i]=arr[i+1];
                 arr[i+1]=temp;
            }
            }
        t++;
    }
    for(int i =0;i<n;i++)
        cout<<arr[i]<<endl;
    end1 = clock();
    cout<<double(end1 - start1)/CLOCKS_PER_SEC;
    return 0;
}
