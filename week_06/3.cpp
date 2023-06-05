//  Given a directed graph, design an algorithm and implement it using a program to find whether
// cycle exists in the graph or not.

// Input Format: 
// Input will be the graph in the form of adjacency matrix or adjacency list. 

// Output Format: 
// Output will be 'Yes Cycle Exists' if cycle exists otherwise print 'No Cycle Exists'.

// Sample I/O Problem III:

// Input:
// 5
// 0 1 1 0 0
// 0 0 0 1 1
// 0 1 0 1 0
// 0 0 0 0 1
// 0 0 0 0 0

// Output:
// No Cycle Exists


#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<list<int>> e;
    vector<bool> vis;
    vector<bool> recstack;
    public:
    Graph(int v){
        this->v=v;
        e.resize(v);
        vis.resize(v,false);
        recstack.resize(v,false);
    }

    void edge(int s,int d){
        e[s].push_back(d);
    }

    bool DFS(int s);
};

bool Graph::DFS(int s){
    if(!vis[s]){
        vis[s]=true;
        recstack[s]=true;
        for(auto &i:e[s]){
            if(!vis[i] && DFS(i)){
                return true;
            }
            else if(recstack[i]){
                return true;
            }
        }
    }
    recstack[s]=false;
    return false;
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
    (g.DFS(0))?cout<<"Yes Cycle Exist"<<endl :cout<<"No Cycle Exist"<<endl;
}
