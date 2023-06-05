// Given a string of characters, design an algorithm and implement it using a program to print all
// possible permutations of the string in lexicographic order. 

// Input Format: 
// String of characters is provided as an input.

// Output Format: 
// Output will be the list of all possible permutations in lexicographic order.

// Sample I/O Problem II:

// Input:
// CAB

// Output:
// ABC
// ACB
// BAC
// BCA
// CAB
// CBA

#include<bits/stdc++.h>
using namespace std;
void permu(string s,int l,int r){
    if(l==r){
        cout<<s<<endl;
        return;
    }
    for(int i=l;i<r;i++){
        swap(s[l],s[i]);
        permu(s,l+1,r);
        swap(s[l],s[i]);
    }
}
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    permu(s,0,s.length());
}