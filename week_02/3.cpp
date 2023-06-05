/*Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K. 

Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains the key element.

Output format: 
The output will have T number of lines. 
For each test case T, output will be the total count i.e. number of times such pair exists.

Sample I/O Problem III:
Input:
2
5 
1 51 84 21 31
20
10
24 71 16 92 12 28 48 14 20 22
4

Output:
2
4
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        int count=0;
        cin>>n;
        vector<int> v(n);
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>v[i];
            m[v[i]]++;
        }
        cin>>k;
        for(int i=0;i<n;i++){
            m[v[i]]--;
            if(m.find(v[i]-k)!=m.end()){
                count++;
            }
            m[v[i]]++;
        }
        cout<<count<<endl<<endl;
    }
}