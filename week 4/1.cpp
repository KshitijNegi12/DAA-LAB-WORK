/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.

Input Format: 
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.

Output Format:
The output will have T number of lines. 
For each test case T, there will be three output lines.
First line will give the sorted array.
Second line will give total number of comparisons.
Third line will give total number of inversions required.

Sample I/O Problem I:
Input:
3
8
23 65 21 76 46 89 45 32
10 
54 65 34 76 78 97 46 32 51 21
15
63 42 223 645 652 31 324 22 553 12 54 65 86 46 325

Output:
21 23 32 45 46 65 76 89
comparisons = 16
inversions = 13
21 32 34 46 51 54 65 76 78 97
comparisons = 22
inversions = 28
12 22 31 42 46 54 63 65 86 223 324 325 553 645 652
comparisons = 43
inversions = 54
*/

#include<bits/stdc++.h>
using namespace std;
int inversion=0;
void display(vector<int>&v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int merge(vector<int>&v,int left,int mid,int right){
    int comp=0;
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
        if(++comp&&v1[i]<=v2[j]){
            v[k++]=v1[i++];
        }
        else{
            v[k++]=v2[j++];
            inversion+=(mid+1)-(left+i);
        }
    }
    while(i<n1){
        v[k++]=v1[i++];
    }
    while(j<n2){
        v[k++]=v2[j++];
    }
    return comp;
}

int merge_sort(vector<int>&v, int left,int right){
    if(left<right){
        int comp=0;
        int mid=left+(right-left)/2;
        comp+=merge_sort(v,left,mid);
        comp+=merge_sort(v,mid+1,right);
        comp+=merge(v,left,mid,right);
        return comp;
    }
    return 0;
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
        int comp=merge_sort(v,0,n-1);
        display(v);
        cout<<"comparisons: "<<comp<<endl;
        cout<<"inversions: "<<inversion<<endl;
        inversion=0;
    }
}