/*You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))

Input Format: 
First line contains m (the size of first array).
Second line contains m space-separated integers describing first array.
Third line contains n (the size of second array).
Fourth line contains n space-separated integers describing second array.

Output Format:
Output will be the list of elements which are common to both.
Sample I/O Problem III:
Input:
7 
10 10 34 39 55 76 85
12
10 10 11 30 30 34 34 51 55 69 72 89

Output:
10 10 34 55
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    vector<int> v1,v2,res;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>k;
        v1.push_back(k);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        v2.push_back(k);
    }
    int p1=0,p2=0;
    while(p1<m&&p2<n){
        if(v1[p1]==v2[p2]){
            res.push_back(v1[p1]);
            p1++;
            p2++;
        }
        else if(v1[p1]>v2[p2]){
            p2++;
        }
        else{
            p1++;
        }
    }
    for(auto i:res){
        cout<<i<<" ";
    }
}