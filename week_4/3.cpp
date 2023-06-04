/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))

Input Format: 
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains K.

Output Format:
The output will have T number of lines. 
For each test case, output will be the Kth smallest or largest array element.
If no Kth element is present, output should be “not present”.

Sample for Kth smallest:
Input:
2
10
123 656 54 765 344 514 765 34 765 234 
3
15
43 64 13 78 864 346 786 456 21 19 8 434 76 270 601
8

Output:
123
78
*/

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v,int node,int left,int right,int size){
	int n=node;
	if(left<=size&&right<=size){
		if(v[left]<v[right]){
			n=left;
		}
		else{
			n=right;
		}
	}
	else if(left<=size&&v[left]<v[node]){
		n=left;
	}
	else if(right<=size&&v[right]<v[node]){
		n=right;
	}
	if(n!=node&&v[n]<v[node]){
		swap(v[n],v[node]);
		heapify(v,n,2*n+1,2*n+2,size);
	}
	}
	
int main(){
	int k,n,t;
    cin>>t;
    while(t--){
        cout<<"Range:";
        cin>>n;
	    vector<int> v;
        for(int i=0;i<n;i++){
            cin>>k;
            v.push_back(k);
        }
        cout<<"Enter kth element: ";
        cin>>k;  

        if(k>n||k<=0){
            cout<<"Invalid number"<<endl;
        }
        else{
            int last_node=n/2-1,left,right;
            for(int i=last_node;i>=0;i--){
                left=2*i+1;
                right=2*i+2;
                heapify(v,i,left,right,n-1);
            }
            for(int i=1;i<=k;i++){
                swap(v[0],v[n-1]);
                n--;
                heapify(v,0,1,2,n-1);
            }
            cout<<"\nKth smallest element: "<<v[n]<<endl;
        }
    }
}