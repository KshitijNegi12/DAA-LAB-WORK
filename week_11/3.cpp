// Given a set of elements, you have to partition the set into two subsets such that the sum of
// elements in both subsets is same. Design an algorithm and implement it using a program to solve
// this problem.

// Input Format:
// First line of input will take number of elements n present in the set. 
// Second line of input will take n space-separated elements of the set.

// Output Format: 
// Output will be 'yes' if two such subsets found otherwise print 'no'.

// Sample I/O Problem III:

// Input:
// 7
// 1 5 4 11 5 14 10 

// Output:
// yes

#include<bits/stdc++.h>
using namespace std;
bool sub(vector<int>&v,int n,int s1,int s2){
    if(s1==s2 && s1!=0 && s2!=0){
        return true;
    }
    if(n<=0){
        return 0;
    }
    return sub(v,n-1,s1+v[n-1],s2) || sub(v,n-1,s1,s2+v[n-1]);
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(sub(v,n,0,0)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no";
    }
}