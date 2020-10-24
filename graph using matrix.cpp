#include<iostream>
using namespace std;

void transposeMatrix(int graph[100][100], int transpose[100][100], int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            transpose[j][i] = graph[i][j];
}

int main()
{
    int n, transpose[100][100], matrix[100][100]; ;
    cout<<"Enter number of nodes : ";
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matrix[i][j] = 0;
    for(int i=0;i<n;i++)
    {
        int e;
        cout<<"Enter number of nodes connected from "<<i<<" : ";
        cin>>e;
        cout<<"Enter those nodes : ";
        for(int j=0;j<e;j++)
        {
            int temp;
            cin>>temp;
            matrix[i][temp] = 1;
        }
    }
    cout<<"adjacency matrix is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"[ ";
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<"]"<<endl;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            transpose[i][j] = 0;

    transposeMatrix(matrix, transpose, n);

    cout<<"Transposed adjacency matrix is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"[ ";
        for(int j=0;j<n;j++)
            cout<<transpose[i][j]<<" ";
        cout<<"]"<<endl;
    }
    return 0;
}