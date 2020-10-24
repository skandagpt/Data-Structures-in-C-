#include<iostream>
using namespace std;
void print(int *,int);
void bubble_sort(int* ,int );

int main(){
    int n;
    cout<<"\nEnter the size of the array\n";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter the elements of array\n";
    for(int i =0;i<n;i++)
        cin>>arr[i];
    cout<<"The given array is :\n";
    print(arr,n);
    
    bubble_sort(arr,n);
    cout<<"The resultant array:\n";
    print(arr,n);
  
    return 0;
}
void bubble_sort(int* arr,int n){
    bool flag=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;}
        }
        if(!flag)
            break;
    }
}

void print(int *arr,int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}