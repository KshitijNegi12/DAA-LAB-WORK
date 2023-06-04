// Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
// deadline associated with it. You have to design an algorithm and implement it using a program to
// find maximum number of tasks that can be completed without crossing their deadlines and also
// find list of selected tasks.

// Input Format: 
// First line will give total number of tasks n. 
// Second line of input will give n space-separated elements of array representing time taken by
// each task. 
// Third line of input will give n space-separated elements of array representing deadline associated
// with each task.

// Output Format: 
// Output will be the total number of maximum tasks that can be completed.

// Sample I/O Problem II:

// Input:
// 7
// 2 1 3 2 2 2 1
// 2 3 8 6 2 5 3

// Output:
// Max number of tasks = 4
// Selected task numbers : 1, 2, 3, 6

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
bool cmp(pair<int,Pair> &i,pair<int,Pair> &j){
    if(i.second.second!=j.second.second){
        return i.second.second<j.second.second;
    }
    return i.second.first<j.second.first;
}
int main(){
    int n,maxi=0;
    cin>>n;
    vector<pair<int,Pair>> v(n);
    for(int i=0;i<n;i++){
        v[i].first=i+1;
        cin>>v[i].second.first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second.second;
        maxi=max(maxi,v[i].second.second);
    }
    sort(v.begin(),v.end(),cmp);
    int job=0,track=0;
    vector<int> taken;
    // pair<int,Pair> p=v[0];
    for(int i=0;i<n;i++){
        int dead=v[i].second.second;
        int comp_time=v[i].second.first;
        if(dead-track>=comp_time){
            job++;
            taken.push_back(v[i].first);
            track+=comp_time;
        }
    }
    cout<<"Max number of tasks = "<<job<<endl;
    cout<<"Selected task numbers : ";
    for(auto i:taken){
        cout<<i<<" ";
    }
}