// Given a directed graph, write an algorithm and a program to find mother vertex in a graph. A
// mother vertex is a vertex v such that there exists a path from v to all other vertices of the graph.

// Input: 
// Graph in the form of adjacency matrix or adjacency list is provided as an input.

// Output: 
// Output will be the mother vertex number.

#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<vector<int>> e;
    public:
    Graph(int v){
        this->v=v;
        e.resize(v);
    }

    void addEdge(int s,int d){
        e[s].push_back(d);
    }

    void DFS(int s,vector<bool>&vis);
    void mother();
};

void Graph::DFS(int s,vector<bool>&vis){
    vis[s]=true;
    for(auto i:e[s]){
        if(!vis[i]){
            DFS(i,vis);
        }
    }
}

void Graph::mother(){
    vector<bool> vis(v,false);
    int mother;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            DFS(i,vis);
            mother=i;
        }
    }
    //checking if it's mother vertex
    vis.assign(v,false);
    DFS(mother,vis);
    for(auto i:vis){
        if(!i){
            cout<<"No mother vertex exist."<<endl;
            return;
        }
    }
    cout<<"Mother vertex is : "<<mother<<endl;
}

int main(){
    Graph g(6);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,5);
    g.addEdge(3,1);
    g.addEdge(4,2);
    g.addEdge(4,5);
    g.mother();

    Graph g2(5);
    g2.addEdge(0,2);
    g2.addEdge(2,1);
    g2.addEdge(3,2);
    g2.addEdge(3,0);
    g2.addEdge(2,4);
    g2.mother();
}