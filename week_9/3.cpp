// Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
// program to merge all these files into single file with minimum computation. For given two files
// A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy
// approach)

// Input Format:
// First line will take the size n of the array. 
// Second line will take array s an input.

// Output Format:
// Output will be the minimum computation cost required to merge all the elements of the array.

// Sample I/O Problem III:

// Input:
// 10
// 10 5 100 50 20 15 5 20 100 10

// Output:
// 960

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,maxi=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        maxi=max(maxi,v[i]);
    }
    vector<int> freq(maxi+1,0);
    for(auto &i:v){
        freq[i]++;
    }
    int cost=0,res=0;
    for(int i=1;i<=maxi;i++){
        if(freq[i]){
            if(res==0){
                res=i;
                freq[i]--;
            }
            while(freq[i]--){
                res+=i;
                cost+=res;
            }
        }
    }
    cout<<cost;
}