#include<iostream>
#include<bits/stdc++.h>


using namespace std;

class Solution {
public:

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal, int n){

        if(col==n){ //all n cols satsified 
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[(n-1)+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[(n-1)+col-row]=1;

                solve(col+1,board,ans, leftRow, upperDiagonal, lowerDiagonal, n);
                
                board[row][col]='.'; //remove Q to make place for others
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[(n-1)+col-row]=0;
                //free hash so that other rows can be checked if sol is found/not found

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; //collection of boards
        vector<string> board(n);  //single solution (**initialise to n)
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0);
        vector<int> upperDiagonal((2*n)-1,0);
        vector<int> lowerDiagonal((2*n)-1,0);

        solve(0,board,ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;

    }
};

int main() {
    int n = 4;
    Solution sol;
    
    vector<vector<string>> result = sol.solveNQueens(n);

    cout <<"Solutions n = "<<n<< endl;
    for (const auto& board : result) {
        for (const auto& row : board) {
            for(const auto &ch : row){
                cout<<ch<<" ";
            }
            cout<<endl;
        }
        cout << endl; 
    }

    return 0;
}


/*
board(n) ans contains many boards
solveNQueens -> initialises data structures 
hash -> checks if queens attack each other
solve -> recursive function that marks Q is sol possible, checks further down that board or backtracks
        free up hash, board[row][col] for backtracking
*/
