// Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
// matrices together. To find the optimal solution, you need to find the order in which these
// matrices should be multiplied. 

// Input Format: 
// First line of input will take number of matrices n that you need to multiply. 
// For each line i in n, take two inputs which will represent dimensions aXb of matrix i.

// Output Format: 
// Output will be the minimum number of operations that are required to multiply the list of
// matrices.

// Sample I/O Problem I:

// Input:
// 3
// 10 30
// 30 5
// 5 60

// Output:
// 4500

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>k;
        if(i==0){
            v.push_back(k);
        }
        cin>>k;
        v.push_back(k);
    }
    n++;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=2;i<n;i++){
        for(int r=0,c=i;r<n-i;r++,c++){
            dp[r][c]=INT_MAX;
            for(k=r+1;k<c;k++){
                dp[r][c]=min(dp[r][c],dp[r][k]+dp[k][c]+(v[r]*v[k]*v[c]));
            }
        }
    }
    cout<<dp[0][n-1];
}