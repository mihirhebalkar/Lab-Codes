#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n=matrix.size();
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (matrix[i][j]==-1) {
					matrix[i][j]=1e9;
				}
				if(i==j)matrix[i][j]= 0;
			}
		}
        
        //for kth intermediate matrix
		for (int k=0;k<n; k++) {  
		    cout<<"\n"<<k+1<<"th intermediate matrix "<<endl;
			for (int i= 0; i<n; i++) {
				for (int j=0; j< n; j++) {
					matrix[i][j]= min(matrix[i][j], matrix[i][k]+matrix[k][j]);
					if(matrix[i][j]!=1e9){
					    cout<<matrix[i][j]<<"   ";
					}
					else{
					    cout<<"inf"<<" ";
					}
				}
				cout<<endl;
			}
		}
        
        
		for (int i =0; i<n; i++) {
			for (int j=0; j< n;j++) {
				if(matrix[i][j]==1e9) {
					matrix[i][j]=-1;
				}
			}
		}
		// -1 represents unreachable
		
    }
};


int main() {

	int V = 4;
	vector<vector<int>> matrix(V,vector<int>(V, -1));
	matrix[0][1]= 2;
	matrix[1][0]= 1;
	matrix[1][2]= 3;
	matrix[3][0]= 3;
	matrix[3][1]= 5;
	matrix[3][2]= 4;

	Solution obj;
	obj.shortest_distance(matrix);

    cout<<"\n\nFloyd Warshall Algorithm Final matrix"<<endl;
    // printing matrix
	for (auto row : matrix) {
		for (auto cell : row) {
		    if(cell<0){
		        cout<<"inf  ";    
		    }
		    else{
		        cout<<" "<<cell<<"   ";
		    }
		}
		cout<<endl;
	}

	return 0;
}
