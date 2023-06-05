// Given an array of nonnegative integers, Design an algorithm and implement it using a program
// to find two pairs (a,b) and (c,d) such that a*b = c*d, where a, b, c and d are distinct elements of
// array.

// Input Format: 
// First line of input will give size of array n. 
// Second line of input will give n space-separated array elements.

// Output Format:
// First line of output will give pair (a,b) 
// Second line of output will give pair (c,d).

// Sample I/O Problem III:

// Input:
// 10
// 31 23 4 1 39 2 20 27 8 10

// Output:
// 4 2
// 1 8

#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,pair<int,int>> m;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val=v[i]*v[j];
            if(m.find(val)!=m.end()){
                cout<<m[val].first<<" "<<m[val].second<<endl;
                cout<<v[i]<<" "<<v[j]<<endl;
                return 0;
            }
            else{
                pair<int,int> p={v[i],v[j]};
                m[val]=p;
            }
        }
    }
}