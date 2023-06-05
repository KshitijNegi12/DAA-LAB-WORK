// Given an array of integers of size n, design an algorithm and write a program to check whether
// this array contains duplicate within a small window of size k < n.

// Input Format:
// First input line contains number of test cases T.
// For each test case T, there will be three input lines.
// First line contains size n of array.
// Second input line contains n space-separated array elements.
// Third input line contains value k.

// Output Format:
// Output will have T number of lines. 
// For each test case, output will be “Duplicate present in window k” if the duplicate element is
// found in the array, otherwise “Duplicate not present in window k”. 

// Sample I/O Problem II:

// Input:
// 2
// 10
// 1 2 3 4 1 2 3 4 1 2 
// 3
// 12
// 1 2 3 1 2 3 1 2 3 1 2 3
// 4

// Output:
// Duplicate not present in window 3.
// Duplicate present in window 4.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cin>>k;
        map<int,int> m;
        bool flag=false;
        for(int i=0;i<k;i++){
            if(m[v[i]]==0){
                m[v[i]]++;
            }
            else{
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"Duplicate present in window "<<k<<endl;
            continue;
        }
        int start=0;
        for(int i=k;i<n;i++){
            m[v[start++]]--;
            if(m[v[i]]==0){
                m[v[i]]++;
            }
            else{
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"Duplicate present in window "<<k<<endl;
            continue;
        }
        cout<<"Duplicate not present in window "<<k<<endl;
    }
}