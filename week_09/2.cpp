// Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. You have to Design an algorithm and implement it using a program to find the list of the
// selected items such that the final selected content has weight w and has maximum value. You can
// take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
// only a fraction xi of item i, where 0 ≤xi≤ 1.

// Input Format: 
// First input line will take number of items N which are provided. 
// Second input line will contain N space-separated array containing weights of all N items.
// Third input line will contain N space-separated array containing values of all N items. 
// Last line of the input will take the maximum capacity w of knapsack.

// Output Format:
// First output line will give maximum value that can be achieved.
// Next Line of output will give list of items selected along with their fraction of amount which has
// been taken.

// Sample I/O Problem II:
// Input:
// 6
// 6 10 3 5 1 3 //weights
// 6 2 1 8 3 5
// 16

// Output:
// Maximum value : 22.338
// item-weight
// 5-1
// 6-3
// 4-5
// 1-6
// 3-1

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
bool cmp(pair<int,Pair> &a,pair<int,Pair>&b){
    double x= (double)a.second.first/a.second.second;
    double y= (double)b.second.first/b.second.second;
    return x>y;
}
void knapsack(vector<pair<int,Pair>>&v,int n,int w){
    sort(v.begin(),v.end(),cmp);
    double ans=0;
    vector<Pair> items;
    for(int i=0;i<n;i++){
        if(w>=v[i].second.second){
            w-=v[i].second.second;
            ans+=v[i].second.first;
            items.push_back({v[i].first,v[i].second.second});
        }
        else{
            items.push_back({v[i].first,w});
            ans+=v[i].second.first*((double)w/v[i].second.second);
            break;
        }
    }
    cout<<"Maximum value : "<<setprecision(5)<<ans<<endl;
    cout<<"item-weight"<<endl;
    for(auto i:items){
        cout<<i.first<<"-"<<i.second<<endl;
    }

}
int main(){
    int n,w;
    cin>>n;
    vector<pair<int,Pair>> v(n);
    for(int i=0;i<n;i++){   //profit
        cin>>v[i].second.second;
    }
    for(int i=0;i<n;i++){   
        v[i].first=i+1;
        cin>>v[i].second.first;
    }
    cin>>w;
    knapsack(v,n,w);
}