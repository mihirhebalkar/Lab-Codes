#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Item {
	int value;
	int weight;
};

class Solution {
	public:
		bool static comp(pair<Item, int>a, pair<Item, int>b){ //to help in sorting
			double r1 = (double) a.first.value /(double) a.first.weight; 
			double r2 = (double) b.first.value /(double) b.first.weight;
			return r1>r2;
		}
		
		pair<double, vector<double>> fk(int W, Item arr[], int n){
//			sort(arr, arr+n, comp);
            vector<pair<Item, int>> ind;
            for (int i = 0; i < n; i++) {
                ind.push_back({arr[i], i}); // Store the item along with its index
            }


            sort(ind.begin(), ind.end(), comp);

			
			vector<double> included(n,0.0);
			int cur=0;
			double final=0.0; //final value
			
			for(int i=0; i<n;i++){
				int idx = ind[i].second;
				
				if(cur + ind[i].first.weight <= W){
					cur += ind[i].first.weight;
					final += ind[i].first.value;
					included[idx]=1;
				}
				else {
					int rem = W-cur;  // remainder weight
					final += (double) rem * (double) ind[i].first.value / (double) ind[i].first.weight;
					included[idx]=(double)rem/(double)ind[i].first.weight;
					break;
				}
			}
			return {final, included};
		}
};

int main() {
   int n = 3, weight = 60;
   Item arr[n] = { {60,15},{100,30},{150,45} };
   Solution obj;
   
   double ans = obj.fk(weight, arr, n).first;
   vector<double> soln = obj.fk(weight, arr, n).second;cout << "The maximum value is " << ans;
   
   
   cout<<"\nElements included are : ";
   for(int i=0; i<n;i++){
   	cout<<soln[i]<<" ";
   }
   return 0;
}



/*
    things to remember -> bool static comp, data structure -> pair<Item, int>  auxillary array that maintains index 
    idx = pair.second    Item -> a.first.value
    First ind structure array and index push
    sort, included vector
    for loop -> extract largest weight to profit, included[idx] = 1 to maintain index
*/
