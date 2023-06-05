/*Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))

Input Format: 
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.

Output Format:
The output will have T number of lines. 
For each test case, output will be 'YES' if duplicates are present otherwise ‘NO’.

Sample I/O Problem III:
Input:
3 
5
28 52 83 14 75
10 
75 65 1 65 2 6 86 2 75 8 
15 
75 35 86 57 98 23 73 1 64 8 11 90 61 19 20

Output:
NO
YES
NO*/

#include<bits/stdc++.h>
using namespace std;
string check_for_duplicate(vector<int> &v,int n){
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]){
            return "YES";
        }
    }
    return "NO";
}
void merge(vector<int>&v,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int> v1(n1),v2(n2);
    for(int i=0;i<n1;i++){
        v1[i]=v[left+i];
    }
    for(int i=0;i<n2;i++){
        v2[i]=v[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(v1[i]<v2[j]){
            v[k++]=v1[i++];
        }
        else{
            v[k++]=v2[j++];
        }
    }
    while(i<n1){
        v[k++]=v1[i++];
    }
    while(j<n2){
        v[k++]=v2[j++];
    }
}

void merge_sort(vector<int>&v, int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(v,left,mid);
        merge_sort(v,mid+1,right);
        merge(v,left,mid,right);
    }
}
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        vector<int> v;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>k;
            v.push_back(k);
        }
        merge_sort(v,0,n-1);
        cout<<check_for_duplicate(v,n)<<endl;
    }
}