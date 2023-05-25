/*Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)

Sample I/O Problem - 1: 
Input:
3
8
34 35 65 31 25 89 64 30 
89
5
977 354 244 546 355
244
6
23 64 13 67 43 56
63

Output:
Present 6
Present 3
Not Present 6*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        bool flag=0;
        int count=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cin>>k;
        for(int i=0;i<n;i++){
            if(++count&&v[i]==k){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"Present "<<count<<endl;
        }
        else{
            cout<<"Not Present "<<count<<endl;
        }
    }
}