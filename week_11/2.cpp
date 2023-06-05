// Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
// For a given value N, you have to Design an algorithm and implement it using a program to find
// number of ways in which these coins can be added to make sum value equals to N.

// Input Format: 
// First line of input will take number of coins that are available. 
// Second line of input will take the value of each coin. 
// Third line of input will take the value N for which you need to find sum.

// Output Format: 
// Output will be the number of ways.

// Sample I/O Problem II:

// Input:
// 4
// 2 5 6 3
// 10

// Output:
// 5

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int coin(vector<int>&v, int n, int k){
    if(k==0){
        return dp[k][n]=1;
    }
    if(k<0 || n<=0){
        return 0;
    }
    if(dp[k][n]!=-1) return dp[k][n];
    return dp[k][n]=coin(v,n-1,k)+coin(v,n,k-v[n-1]);
}
int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    dp=vector<vector<int>> (k+1,vector<int>(n+1,-1));
    cout<<coin(v,n,k)<<endl;
}