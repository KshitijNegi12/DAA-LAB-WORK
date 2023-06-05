// Design an algorithm and implement it using a program to solve previous question's problem
// using Bellman- Ford's shortest distance algorithm.

// Input Format: 
// Input will be the graph in the form of adjacency matrix or adjacency list. 
// Source vertex number is also provided as an input.

// Output Format: 
// Output will contain V lines.
// Each line will represent the whole distance from destination vertex number to source vertex number
// along with minimum distance weigth.

// Sample I/O Problem I and II:
// Input:
// 5
// 0 4 1 0 0
// 0 0 0 0 4
// 0 2 0 2 0
// 0 0 0 0 4
// 0 0 0 0 0
// 1

// Output:
// 1 : 0
// 2 3 1 : 3
// 3 1 : 1
// 4 3 1 : 3
// 5 2 3 1 : 7

#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<vector<int>> e;
    public:
    Graph(int v){
        this->v=v;;
    }

    void edge(int s,int d,int w){
        e.push_back({s,d,w});
        e.push_back({d,s,w});
    }
    void BellmanFord(int ,int e);
    void print(vector<int> distance, vector<int> parent); 
};

void path(int source,vector<int> parent){
    if(parent[source]==-1){
        return;
    }
    cout<<parent[source]+1<<" ";
    path(parent[source],parent);
}

void Graph::print(vector<int> distance, vector<int> parent){
    for(int i=0;i<v;i++){
        cout<<i+1<<" ";
        path(i,parent);
        cout<<": "<<distance[i]<<endl;
    }
}

void Graph::BellmanFord(int source,int edges){
    vector<int> distance(v,INT_MAX),parent(v);
    distance[source]=0;
    parent[source]=-1;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<edges;j++){
            if(distance[e[j][0]]!=INT_MAX && distance[e[j][0]]+e[j][2]<distance[e[j][1]]){
                distance[e[j][1]]=distance[e[j][0]]+e[j][2];
                parent[e[j][1]]=e[j][0];
            }
        }
    }
    print(distance,parent);
}
int main(){
    int v,k,e=0;
    cin>>v;
    Graph g(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>k;
            if(k!=0){
                e+=2;
                g.edge(i,j,k);
            }
        }
    }
    int s;
    cin>>s;
    g.BellmanFord(s-1,e);
}