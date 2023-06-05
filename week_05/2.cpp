/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))

Input Format: 
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains key

Output Format:
The output will have T number of lines. 
For each test case, output will be the elements arr[i] and arr[j] such that arr[i]+arr[j] = key if exist
otherwise print 'No Such Elements Exist”.

Sample I/O Problem II: 
Input:
2
10
64 28 97 40 12 72 84 24 38 10
50
15 
56 10 72 91 29 3 41 45 61 20 11 39 9 12 94
302

Output:
10 40
No Such Element Exist
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,sum;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cin>>sum;
        sort(v.begin(),v.end());
        int l=0,r=n-1;
        bool flag=0;
        while(l<r){
            if(v[l]+v[r]==sum){
                cout<<v[l]<<" "<<v[r]<<endl;
                flag=1;
                break;
            }
            else if(v[l]+v[r]>sum){
                r--;
            }
            else{
                l++;
            }
        }
        if(flag==0){
            cout<<"No Such Element Exist"<<endl;
        }
    }
}