// After end term examination, Akshay wants to party with his friends. All his friends are living as
// paying guest and it has been decided to first gather at Akshay’s house and then move towards
// party location. The problem is that no one knows the exact address of his house in the city.

// Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
// came up with an amazing idea to help his friends. He draws a graph by looking in to location of
// his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
// shortest distance and path covering that distance from each of his friend’s location to his house
// and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
// developed the program that implements Dijkstra’s algorithm but not sure about correctness of
// results. Can you also implement the same algorithm and verify the correctness of Akshay’s
// results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)

// Input Format: 
// Input will be the graph in the form of adjacency matrix or adjacency list. 
// Source vertex number is also provided as an input.

// Output Format: 
// Output will contain V lines.
// Each line will represent the whole path from destination vertex number to source vertex number
// along with minimum path weigth.

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
    vector<list<pair<int,int>>> e;
    vector<bool> vis;
    vector<bool> recstack;
    public:
    Graph(int v){
        this->v=v;
        e.resize(v);
        vis.resize(v,false);
        recstack.resize(v,false);
    }

    void edge(int s,int d,int w){
        e[s].push_back({d,w});
        e[d].push_back({s,w});
    }

    void Dijsktra(int source);
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
class cmp{
    public:
    typedef pair<int,int> Pair;
    bool operator()(Pair &a,Pair &b){
        return a.second<b.second;
    }
};

void Graph::Dijsktra(int source){
    typedef pair<int,int> Pair;
    priority_queue<Pair,vector<Pair>,cmp> q;
    vector<int> parent(v);
    vector<int> res(v,INT_MAX);
    res[source]=0;
    parent[source]=-1;
    q.push({source,0});

    while(!q.empty()){
        Pair temp=q.top();
        q.pop();
        int u=temp.first;
        for(auto &i:e[u]){
            int d=i.first;
            int w=i.second;
            if(res[d]>res[u]+w){
                parent[d]=u;
                res[d]=res[u]+w;
                q.push({d,res[d]});
            }
        }
    }
    print(res,parent);
}

int main(){
    int v,k;
    cin>>v;
    Graph g(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>k;
            if(k!=0){
                g.edge(i,j,k);
            }
        }
    }
    int s;
    cin>>s;
    g.Dijsktra(s-1);
}