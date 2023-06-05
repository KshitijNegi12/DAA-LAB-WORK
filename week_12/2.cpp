// Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. Design an algorithm and implement it using a program to find the list of the selected
// items such that the final selected content has weight <= w and has maximum value. Here, you
// cannot break an item i.e. either pick the complete item or don't pick it. (0-1 property).

// Input Format: 
// First line of input will provide number of items n. 
// Second line of input will take n space-separated integers describing weights for all items.
// Third line of input will take n space-separated integers describing value for each item. 
// Last line of input will give the knapsack capacity.

// Output Format: 
// Output will be maximum value that can be achieved and list of items selected along with their
// weight and value.

// Sample I/O Problem I:

// Input:
// 5
// 2 3 3 4 6
// 1 2 5 9 4
// 10

// Output:
// Value = 16
// Weights selected : 3 3 4
// Values of selected weights : 2 5 9

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }
    cin>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j>=v[i].first){
                int left=j-v[i].first;
                int prev=dp[i][j];
                int curr=dp[i][left]+v[i].second;
                dp[i+1][j]=max(prev,curr);
            }
            else{
                dp[i+1][j]=dp[i][j];
            }
        }
    }
    cout<<dp[n][k];
}