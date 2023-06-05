// Assume that a project of road construction to connect some cities is given to your friend. Map of
// these cities and roads which will connect them (after construction) is provided to him in the form
// of a graph. Certain amount of rupees is associated with construction of each road. Your friend
// has to calculate the minimum budget required for this project. The budget should be designed in
// such a way that the cost of connecting the cities should be minimum and number of roads
// required to connect all the cities should be minimum (if there are N cities then only N-1 roads
// need to be constructed). He asks you for help. Now, you have to help your friend by designing an
// algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)

// Input Format: 
// The first line of input takes number of vertices in the graph. 
// Input will be the graph in the form of adjacency matrix or adjacency list. 

// Output Format:
// Output will be minimum spanning weight

// Sample I/O Problem I and II:

// Input:
// 7
// 0 0 7 5 0 0 0
// 0 0 8 5 0 0 0
// 7 8 0 9 7 0 0
// 5 5 9 0 15 6 0
// 0 0 7 15 0 8 9
// 0 0 0 6 8 0 11
// 0 0 0 0 9 11 0

// Output:
// Minimum Spanning Weight: 39

#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<vector<pair<int,int>>> e;
    public:
    Graph(int v){
        this->v=v;
        e.resize(v);
    }

    void edge(int s,int d,int w){
        e[s].push_back({w,d});
    }

    void prims(){
        int s=0;
        vector<bool> vis(v,false);
        vector<int> cost(v,INT_MAX),parent(v,-1);
        typedef pair<int,int> Pair;
        priority_queue<Pair,vector<Pair>,greater<Pair>> q;
        cost[s]=0;
        q.push({cost[s],s});
        while(!q.empty()){
            int u=q.top().second;
            q.pop();
            if(vis[u]) continue;
            vis[u]=true;
            for(auto &i:e[u]){
                int w=i.first;
                int v=i.second;
                if(!vis[v] && cost[v]>w){
                    cost[v]=w;
                    q.push({cost[v],v});
                    parent[v]=u;
                }
            }
        }
        int res=0;
        for(auto i:cost){
            res+=i;
        }
        cout<<"Minimum Spanning Weight: "<<res;
    }
};
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
    g.prims();
}