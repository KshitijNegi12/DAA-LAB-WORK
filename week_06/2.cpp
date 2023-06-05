// Given a graph, design an algorithm and implement it using a program to find if a graph is
// bipartite or not. (Hint: use BFS)

// Input Format: 
// Input will be the graph in the form of adjacency matrix or adjacency list. 

// Output Format: 
// Output will be 'Yes Bipartite' if graph is bipartite, otherwise print 'Not Bipartite'.

// Sample I/O Problem II:

// Input:
// 5
// 0 1 1 0 0
// 1 0 1 1 1
// 1 1 0 1 0
// 0 1 1 0 1
// 0 1 0 1 0

// Output:
// Not Bipartite

#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<list<int>> e;
    vector<int> color;
    public:
    Graph(int v){
        this->v=v;
        e.resize(v);
        color.resize(v,-1);
    }

    void edge(int s,int d){
        e[s].push_back(d);
    }

    bool BFS(int s);
};
bool Graph::BFS(int s){
    queue<int> q;
    q.push(s);
    color[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &i:e[u]){
            if(u==i) return false;  //self loop
            if(color[i]==-1){
                color[i]=1-color[u];
                q.push(i);
            }
            else if(color[i]==color[u]){
                return false;
            }
        }
    }
    return true;
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
    (g.BFS(0))?cout<<"Yes Bipartite" : cout<<"No Bipartite";
}
