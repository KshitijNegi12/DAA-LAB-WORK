// Given a list of activities with their starting time and finishing time. Your goal is to select
// maximum number of activities that can be performed by a single person such that selected
// activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
// activity is greater than or equal to the finishing time of the other activity. Assume that a person
// can only work on a single activity at a time.

// Input Format: 
// First line of input will take number of activities N. 
// Second line will take N space-separated values defining starting time for all the N activities. 
// Third line of input will take N space-separated values defining finishing time for all the N
// activities.

// Output Format: 
// Output will be the number of non-conflicting activities and the list of selected activities.

// Sample I/O Problem I:

// Input:
// 10
// 1 3 0 5 3 5 8 8 2 12
// 4 5 6 7 9 9 11 12 14 16

// Output:
// No. of non-conflicting activities: 4
// List of selected activities: 1, 4, 7, 10

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
bool cmp(Pair &i,Pair &j){
    if(i.second!=j.second){
        return i.second<j.second;
    }
    return i.first<j.first;
}
int main(){
    int n;
    cin>>n;
    vector<Pair> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    int job=1;
    vector<int> taken;
    Pair p=v[0];
    taken.push_back(1);
    for(int i=0;i<n;i++){
        if(p.second<=v[i].first){
            job++;
            p=v[i];
        taken.push_back(i+1);
        }
    }
    cout<<"No. of non-conflicting activities: "<<job<<endl;
    cout<<"List of selected activities: ";
    for(auto i:taken){
        cout<<i<<" ";
    }
}