// Given a (directed/undirected) graph, design an algorithm and implement it using a program to
// find if a path exists between two given vertices or not. (Hint: use DFS)

// Input Format: 
// Input will be the graph in the form of adjacency matrix or adjacency list. 
// Source vertex number and destination vertex number is also provided as an input.

// Output Format: 
// Output will be 'Yes Path Exists' if path exists, otherwise print 'No Such Path Exists'.

// Sample I/O Problem I:

// Input:
// 5
// 0 1 1 0 0
// 1 0 1 1 1
// 1 1 0 1 0
// 0 1 1 0 1
// 0 1 0 1 0
// 1 5

// Output:
// Yes Path Exists

#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<list<int>> e;
    vector<bool> vis;
    public:
    Graph(int v){
        this->v=v;
        e.resize(v);
        vis.resize(v,false);
    }

    void edge(int s,int d){
        e[s].push_back(d);
    }

    void DFS(int s);
    void check(int d);
};

void Graph::DFS(int s){
    if(!vis[s]){
        vis[s]=true;
        for(auto &i:e[s]){
            DFS(i);
        }
    }
}

void Graph::check(int d){
    if(vis[d]){
        cout<<"Yes Path Exists"<<endl;
    }
    else{
        cout<<"No Such Path Exists"<<endl;
    }
}
int main(){
    int v,k;
    cin>>v;
    Graph g(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>k;
            if(k==1){
                g.edge(i,j);
            }
        }
    }
    int s,d;
    cin>>s>>d;
    g.DFS(s-1);
    g.check(d-1);
}