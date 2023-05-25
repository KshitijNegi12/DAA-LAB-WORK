/*Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and print it.

Input Format: 
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.

Output:
The output will have T number of lines. 
For each test case, output will be the array element which has maximum occurrences and its total
number of occurrences. 
If no duplicates are present (i.e. all the elements occur only once), output should be “No
Duplicates Present”.

Sample I/O Problem I:
Input:
3
10
a e d w a d q a f p 
15
r k p g v y u m q a d j c z e
20
g t l l t c w a w g l c w d s a a v c l 

Output:
a – 3
No Duplicates Present
l - 4
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        unordered_map<char,int> m;
        cin>>n;
        vector<char> s;
        for(int i=0;i<n;i++){
            char ch;
            cin>>ch;
            s.push_back(ch);
            m[ch]++;
        }
        char ch='@';
        int max=INT_MIN;
        for(auto i:m){
            if(i.second>1&&i.second>max){
                max=i.second;
                ch=i.first;
            }
        }
        if(ch!='@'){
            cout<<ch<<" - "<<max<<endl;
        }
        else{
            cout<<"No Duplicate Present"<<endl;
        }

    }
}