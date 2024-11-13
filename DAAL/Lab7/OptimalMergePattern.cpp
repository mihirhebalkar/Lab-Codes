#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int optimalMergePattern(vector<int> files, int n){
	priority_queue<int, vector<int>, greater<int>> minheap; //min heap -> greater<int>
	
	for(int i=0; i<n;i++){
		minheap.push(files[i]);
	}
	
	int ans=0;
	
	while(minheap.size()>1){
		int e1=minheap.top();
		minheap.pop();
		
		int e2=minheap.top();
		minheap.pop();
		
		ans+=e1+e2;
		
		minheap.push(e1+e2); //e1, e2 removed using pop from minheap and sum added in minheap
	}
	
	return ans;
}


int main(){
	
	int n;
	
	cout<<"Enter number of files : ";
	cin>>n;
	
	vector<int> files(n);
	
	cout<<"Enter computation time : ";
	
	for(int i=0; i<n;i++){
		cin>>files[i];
	}
	
	int ans = optimalMergePattern(files, n);
	
	cout<<"Total Cost : "<<ans;
	
	
	
	return 0;
}

