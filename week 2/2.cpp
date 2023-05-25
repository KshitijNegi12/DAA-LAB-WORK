/*Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. 

Input format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.

Output: 
The output will have T number of lines. 
For each test case T, print the value of i, j and k, if found else print “No sequence found”.

Sample I/O Problem II:
Input:
3
5 
1 5 84 209 341
10
24 28 48 71 86 89 92 120 194 201
15
64 69 82 95 99 107 113 141 171 350 369 400 511 590 666 

Output:
No sequence found.
2, 7, 8
1, 6, 9
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n);
        vector<vector<int>> res;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>v[i];
            m[v[i]]=i;
        }
        for(int i=0;i<n-2;i++){
            m.erase(v[i]);
            for(int j=i+1;j<n-1;j++){
                m.erase(v[j]);
                if(m.find(v[i]+v[j])!=m.end()){
                    int k=m[v[i]+v[j]];
                    res.push_back({i+1,j+1,k+1});
                }
                m[v[j]]=j;
            }
        }
        if(res.empty()){
            cout<<"No subsequence found."<<endl;
        }
        else{
            for(auto i:res){
                for(auto j:i){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
}