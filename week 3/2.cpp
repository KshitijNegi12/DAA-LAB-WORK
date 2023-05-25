/*Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.

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
Third line will give total number of swaps required.

Sample I/O Problem II:
Input:
3
8
-13 65 -21 76 46 89 45 12
10 
54 65 34 76 78 97 46 32 51 21
15
63 42 223 645 652 31 324 22 553 12 54 65 86 46 325

Output:
-21 -13 12 45 46 65 76 89
comparisons = 28
swaps = 7
21 32 34 46 51 54 65 76 78 97
comparisons = 45
swaps = 9
12 22 31 42 46 54 63 65 86 223 324 325 553 645 652
comparisons = 105
swaps = 14*/

#include<bits/stdc++.h>
using namespace std;

void display(vector<int>&v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
void selection_sort(vector<int>&v,int n){
    int comp=0,swaps=0,temp;
    for(int i=0;i<n-1;i++){
        temp=i;
        for(int j=i+1;j<n;j++){
            if(++comp&&v[temp]>v[j]){
                temp=j;
            }
        }
        swap(v[temp],v[i]);
        swaps++;
    }
    display(v);
    cout<<"comparison: "<<comp<<endl;
    cout<<"swap: "<<swaps<<endl;
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
        selection_sort(v,n);
    }
}