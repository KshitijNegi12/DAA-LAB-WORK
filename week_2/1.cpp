/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))

Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains the key element that need to be searched in the array.

Output format: 
The output will have T number of lines. 
For each test case T, output will be the key element and its number of copies in the array if the
key element is present in the array otherwise print “ Key not present”.

Sample I/O Problem I:
Input:
2
10 
235 235 278 278 763 764 790 853 981 981 
981
15 
1 2 2 3 3 5 5 5 25 75 75 75 97 97 97
75

Output:
981 - 2
75 - 3
*/

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
        vector<int>::iterator l,r;
        l=lower_bound(v.begin(),v.end(),k);
        if(l==v.end()||*l!=k){
            cout<<"Not Present "<<endl;
            continue;
        }
        r=upper_bound(v.begin(),v.end(),k);
        cout<<k<<" - "<<(r-v.begin())-(l-v.begin())<<endl;
    }
}