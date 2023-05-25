/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on.
Once the interval(arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the element key.

(Complexity < O(n), where n is the number of elements need to be scanned for searching):Jump Search

Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains n space-separated integers describing array.
Third line contains the key element that need to be searched in the array.

Output format:
The output will have T number of lines. 
For each test case, output will be “Present” if the key element is found in the array, otherwise
“Not Present”. 
Also for each test case output the number of comparisons required to search the key.

Sample I/O Problem - 2, 3:
Input:
3 
5
12 23 36 39 41
41
8
21 39 40 45 51 54 68 72
69
10
101 246 438 561 796 896 899 4644 7999 8545 
7999

Output:
Present 2
Not Present 3
Present 3
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
        int start=0,jump=sqrt(n),end=jump;
        for(int i=jump;i<n;i+=jump){
            if(++count&&v[i]>k){
                break;
            }
            start=i;
            end+=jump;
        }
        for(int i=start;i<min(end,n);i++){
            if(v[i]==k){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"Present "<<count<<endl;
        }
        else{
            cout<<"Not Present "<<count<<endl;
        }
    }
}