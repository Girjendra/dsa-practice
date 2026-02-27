/*
Problem statement
The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that
no two queens attack each other.
Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.
Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 
*/


#include <bits/stdc++.h> 
using namespace std;

// TC: O(N!)
// SC: O(N*N)

void addsolution(vector<vector<int>>& board, vector<vector<int>>& ans, int n) {
    vector<int> temp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n ;j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool issafe(int row, int col, vector<vector<int>>& board, int n) {
    int x = row;
    int y = col;

    while(y >= 0) { // map<row, bool> for O(1) check
        if(board[x][y] == 1)
            return false;
        y--;
    }

    x = row;
    y = col;
    while(x >= 0 && y >= 0) {  // map<n-1+col-row, bool> for O(1) check
        if(board[x][y] == 1)
            return false;
        y--;
        x--;
    }

    x = row;
    y = col;
    while(x < n && y >= 0) { // map<row+col, bool> for O(1) check
        if(board[x][y] == 1)
            return false;
        y--;
        x++;
    }

    return true;
}

void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, int n) {
    if(col == n) {
        addsolution(board, ans, n);
        return;
    }

    for(int row=0; row<n; row++) {
        if(issafe(row, col, board,n)) {
            board[row][col] = 1;
            solve(col+1, board, ans, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n) {
	vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, board, ans, n);

    return ans;
}