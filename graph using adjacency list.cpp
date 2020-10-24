#include<iostream>
#include<vector>
using namespace std;

void Edge(vector<int> graph[], int start, int end) 
{ 
    graph[start].push_back(end); 
} 

void transposeList(vector<int> graph[], vector<int> transpose[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        for (unsigned int j = 0; j < graph[i].size(); j++) 
            Edge(transpose, graph[i][j] , i); 
} 

int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    vector<int> G[n]; 
    for(int i=0;i<n;i++)
    {
        int e;
        cout<<"Enter number of nodes connected from "<<i<<" :  ";
        cin>>e;
        cout<<"Enter those nodes : ";
        for(int j=0 ; j<e ; j++)
        {
            int temp;
            cin>>temp;
            Edge(G,i,temp);
        }
    }
    cout<<"Adjacency list is : "<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<i<<" -> ";
        for(int j =0 ; j<G[i].size(); j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
    vector<int> Transpose[n];
    transposeList(G, Transpose, n);
    cout<<"Transposed adjacency list is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        for(int j = 0 ; j<Transpose[i].size();j++)
            cout<<Transpose[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}