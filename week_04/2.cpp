/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.

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
23 65 21 76 46 89 45 32
10 
54 65 34 76 78 97 46 32 51 21
15
63 42 223 645 652 31 324 22 553 12 54 65 86 46 325

Output:
21 23 32 45 46 65 76 89
comparisons = 14
swaps = 10
21 32 34 46 51 54 65 76 78 97
comparisons = 29
swaps = 21
12 22 31 42 46 54 63 65 86 223 324 325 553 645 652
comparisons = 45
swaps = 39
*/

#include<bits/stdc++.h>
using namespace std;
int comp=0,swaps=0;
void display(vector<int>&v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int partition(vector<int>&v,int left,int right){
    int pi=v[right];
    int j=left;
    for(int i=left;i<right;i++){
        if(++comp&&v[i]<pi){
            swap(v[i],v[j]);
            j++;
            swaps++;
        }
    }
    swaps++;
    swap(v[right],v[j]);
    return j;
}

void quick_sort(vector<int>&v, int left,int right){
    if(left<right){
        int pi=partition(v,left,right);
        quick_sort(v,left,pi-1);
        quick_sort(v,pi+1,right);
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
        quick_sort(v,0,n-1);
        display(v);
        cout<<"comparisons: "<<comp<<endl;
        cout<<"swaps: "<<swaps<<endl;
        comp=0,swaps=0;
    }
}