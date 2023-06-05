// Given two sequences, Design an algorithm and implement it using a program to find the length
// of longest subsequence present in both of them. A subsequence is a sequence that appears in the
// same relative order, but not necessarily contiguous.

// Input Format: 
// First input line will take character sequence 1.
// Second input line will take character sequence 2.

// Output Format: 
// Output will be the longest common subsequence along with its length.

// Sample I/O Problem I:

// Input:
// Sequence1: AGGTAB
// Sequence2: GXTXAYB

// Output:
// Longest Common Subsequence: GTAB
// length = 4

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.size();
    int n2=s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int l=dp[n1][n2];
    char str[l];
    str[l]='\0';
    int i=n1,j=n2;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            str[--l]=s1[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<"Longest Common Subsequence: "<<str<<endl;
    cout<<"length = "<<dp[n1][n2];
}