// Given an unsorted array of elements, design an algorithm and implement it using a program to
// find whether majority element exists or not. Also find median of the array. A majority element is
// an element that appears more than n/2 times, where n is the size of array.

// Input Format: 
// First line of input will give size n of array. 
// Second line of input will take n space-separated elements of array.

// Output Format: 
// First line of output will be 'yes' if majority element exists, otherwise print 'no'. 
// Second line of output will print median of the array.

// Sample I/O Problem III:
// Input:
// 9
// 4 4 2 3 2 2 3 2 2
// Output:
// yes
// 2

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int vot=0,p;
    for(int i=0;i<n;i++){
        if(vot==0){
            p=v[i];
            vot++;
        }
        else if(v[i]!=p){
            vot--;
        }
        else{
            vot++;
        }
    }
    int freq=0;
    for(int i=0;i<n;i++){
        if(v[i]==p) freq++;
    }
    if(freq>=n/2){
        cout<<"YES"<<endl;
        cout<<p<<endl;
    }
    else{
        cout<<"NO";
    }
    
}