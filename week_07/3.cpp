// Given a directed graph with two vertices ( source and destination). Design an algorithm and
// implement it using a program to find the weight of the shortest path from source to destination
// with exactly k edges on the path.

// Input Format: 

// First input line will obtain number of vertices V present in the graph.
// Graph in the form of adjacency matrix or adjacency list is taken as an input in next V lines. 
// Next input line will obtain source and destination vertex number.
// Last input line will obtain value k.

// Output Format: 

// Output will be the weigth of shortest path from source to destination having exactly k edges. 
// If no path is available then print “no path of length k is available”.

// Sample I/O Problem III:

// Input:
// 4
// 0 10 3 2
// 0 0 0 7
// 0 0 0 6
// 0 0 0 0 
// 1 4
// 2

// Output:
// Weight of shortest path from (1,4) with 2 edges : 9

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
        e[s].push_back({d,w});
    }
    
    int findpath(int s,int d,int n){
        if(n==0 && s==d){
            return 0;
        }
        if(n==0){
            return INT_MAX;
        }
        int dist=INT_MAX;
        for(auto &i:e[s]){
            int temp=findpath(i.first,d,n-1);
            if(temp!=INT_MAX){
                dist=min(dist,temp+i.second);
            }
        }
        return dist;
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
    int s,d,e;
    cin>>s>>d>>e;
    int path=g.findpath(s-1,d-1,e);
    if(path==INT_MAX){
        cout<<"No path of length "<<e<<" is available"<<endl;
    }
    else{
        cout<<"Weight of shortest path from ("<<s<<","<<e<<") with "<<e<<" edges : "<<path<<endl;
    }
}