#include <iostream> 
using namespace std; 
  
void heapify(int *arr, int n, int i) 
{ 
    int largest = i;  
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i)
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 

void display(int *arr, int n ) 
{ 
    cout << "Array representation of Heap is : " <<endl; 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << endl;
}  

void buildHeap(int *arr, int n) 
{ 
    int start = (n / 2) - 1; 
    for (int i = start; i >= 0; i--) 
    { 
        heapify(arr, n, i); 
    } 
} 

int max(int *arr)
{
   return arr[0];
}

int extractmax(int *arr , int n)
{
   int max = arr[0];
   swap(arr[0] , arr[n-1]);
   n = n-1;
   cout<< max <<endl;
   buildHeap(arr , n);
   display(arr , n);
   return n;
}

int insert(int *arr , int n , int i)
{
   arr[n] = i;
   n = n+1;
   buildHeap(arr , n);
   return n;
}


int main() 
{ 
   int n , i;
   int *arr;
   cout<<"Enter no of elements in heap : ";
   cin>>n;
   for(int i =0 ; i<n ; i++)
      cin>>arr[i];
   buildHeap(arr, n); 
   display(arr, n); 
   cout<<"The maximum of heap is : "<<max(arr)<<endl;
   cout<<"insert element in queue : ";
   cin>>i;
   n = insert(arr , n , i);
   display(arr , n);
   cout<<"Extracting maximum : " <<endl ;
   n = extractmax(arr , n);
    return 0; 
} 