// Given a number n, write an algorithm and a program to find nth ugly number. Ugly numbers are
// those numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12,
// 15, 16, 18, 20, 24,..... is sequence of ugly numbers.

// Input: 
// First line of input will give number of test cases T. 
// For each test case T, enter a number n.

// Output: 
// There will be T output lines. 
// For each test case T, Output will be nth ugly number.

// Sample I/O Problem I:

// Input:
// 3
// 11
// 8
// 15

// Output:
// 15
// 9
// 24

#include<bits/stdc++.h>
using namespace std;

int reduce(int m, int n){
    while(m%n==0){
        m=m/n;
    }
    return m;
}
bool check(int n){
    n=reduce(n,2);
    n=reduce(n,3);
    n=reduce(n,5);
    return (n==1)?1:0;
}
int ugly(int n){
    int i=1;
    int count=1;
    while(count < n){
        i++;
        if(check(i)){
            count++;
        }
    }
    return i;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ugly(n)<<endl;
    }
}