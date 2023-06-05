// Given an array of characters, you have to find distinct characters from this array. Design an
// algorithm and implement it using a program to solve this problem using hashing. (Time
// Complexity = O(n))

// Input Format:
// First line of input will give the size n of the character array. 
// Second line of input will give n space-separated elements to character array.

// Output Format: 
// Output will be the list of characters present in the array in alphabetical order
// and frequency of each character in the array.

// Sample I/O Problem I:

// Input:
// 20
// a e d e f j t t z a z f t a e e k a e q

// Output:
// a 4
// d 1
// e 5
// f 2
// j 1
// k 1
// q 1
// t 3
// z 2

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> m(26);
    for(int i=0;i<n;i++){
        m[v[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(m[i]){
            cout<<(char)(i+'a')<<" "<<m[i]<<endl;
        }
    }
}