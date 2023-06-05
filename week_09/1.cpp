// Given a graph, Design an algorithm and implement it using a program to implement Floyd-Warshall all pair shortest path algorithm.

// Input Format: 
// The first line of input takes number of vertices in the graph. 
// Input will be the graph in the form of adjacency matrix or adjacency list. If a direct edge is not
// present between any pair of vertex (u,v), then this entry is shown as AdjM[u,v] = INF=-1.

// Output Format: 
// Output will be shortest distance matrix in the form of V X V matrix, where each entry (u,v)
// represents shortest distance between vertex u and vertex v.

// Sample I/O Problem I:

// Input:
// 5
// 0 10 5 5 -1
// -1 0 5 5 5
// -1 -1 0 -1 10
// -1 -1 -1 0 20
// -1 -1 -1 5 0

// Output:
// Shortest Distance Matrix:
// 0 10 5 5 15
// -1 0 5 5 5
// -1 -1 0 15 10
// -1 -1 -1 0 20
// -1 -1 -1 5 0

#include<bits/stdc++.h>
using namespace std;
int main(){
    int v,k;
    cin>>v;
    vector<vector<int>> e(v,vector<int>(v,INT_MAX));
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>k;
            if(k!=-1){
                e[i][j]=k;
            }
        }
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(j==i || k==j || e[j][i]==INT_MAX || e[i][k]==INT_MAX) continue;
                e[j][k]=min(e[j][k],e[j][i]+e[i][k]);
            }
        }
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(e[i][j]==INT_MAX)
            cout<<-1<<" ";
            else
            cout<<e[i][j]<<" ";
        }
        cout<<endl;
    }
}