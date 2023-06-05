// Assume that a project of road construction to connect some cities is given to your friend. Map of
// these cities and roads which will connect them (after construction) is provided to him in the form
// of a graph. Certain amount of rupees is associated with construction of each road. Your friend
// has to calculate the minimum budget required for this project. The budget should be designed in
// such a way that the cost of connecting the cities should be minimum and number of roads
// required to connect all the cities should be minimum (if there are N cities then only N-1 roads
// need to be constructed). He asks you for help. Now, you have to help your friend by designing an
// algorithm which will find minimum cost required to connect these cities. (use kruskal's algorithm)

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
class DSU{
    vector<int> parent,rank;
    public:
    DSU(int n){
        parent.resize(n,-1);
        rank.resize(n,1);
    }

    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]=find(parent[i]);
    }

    void Union(int a,int b){
        int s1=find(a);
        int s2=find(b);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
            }
            else if(rank[s1]>rank[s2]){
                parent[s2]=s1;
            }
            else{
                parent[s2]=s1;
                rank[s1]+=1;
            }
        }
    }
};

class Graph{
    int v;
    vector<vector<int>> e;
    public:
    Graph(int v){
        this->v=v;
    }

    void edge(int s,int d,int w){
        e.push_back({w,s,d});
    }

    void kruskals(){
        int s=0,cost=0;
        sort(e.begin(),e.end());
        DSU d(v);
        for(auto &i:e){
            int w=i[0];
            int u=i[1];
            int v=i[2];

            if(d.find(u)!=d.find(v)){
                d.Union(u,v);
                cost+=w;
            }
        }
        cout<<"Minimum Spanning Weight: "<<cost;
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
    g.kruskals();
}