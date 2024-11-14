#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+2;
int val[N], wt[N];
int dp[N][N];  //for memoization

int knapsack(int n, int w){
	if(n==0 || w==0){
		return 0;
	}
	
	if(dp[n][w]!=-1){
		return dp[n][w];
	}
	
	if(wt[n]>w){
		dp[n][w] =  knapsack(n-1, w); //exclude element
	}
	else{
		dp[n][w] = max(knapsack(n-1, w), knapsack(n-1,w-wt[n]) + val[n]);  //include element
		
	}
	return dp[n][w];
}
	
	
int main(){
	int n;
	cout<<"Enter number of elements : ";
	cin>>n;
	
	int w;
	cout<<"Enter knapsack capacity : ";
	cin>>w;
	
	
	for(int i=0; i<=n;i++){
		for(int j=0; j<=w;j++){
			dp[i][j] = -1;
		}
	}
	
	cout<<"Enter weight : ";
	for(int i=1; i<=n;i++){
		cin>>wt[i];
	}
	
	cout<<"Enter value : ";
	for(int i=1; i<=n;i++){
		cin>>val[i];
	}
	

	cout<<knapsack(n,w)<<endl;
	
	int total = w;
	vector<int> included(n+1,0);
	
	for(int i=n; i>0; i--){
		if(dp[i][total]!=dp[i-1][total]){
			included[i]=1;
			total-=wt[i];
		}
	}
	
	for(int i=1; i<=n;i++){
		cout<<included[i]<<" ";
	}
	
}
/*
    This code uses 1-based indexing for val, wt arrays.
    It uses DP, memoization to solve the problem, also prints the included array.
*/
