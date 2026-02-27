/*
Problem statement
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. The empty cells of the Sudoku
are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill
all the empty cells such that the final matrix represents a Sudoku solution.
Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.
*/

#include <bits/stdc++.h> 
using namespace std;

// TC: O(9^(N)) N = number of empty cells
// SC: O(1)
bool issafe(int row, int col, vector<vector<int>>& sudoku, int val) {
    for(int i=0 ; i<sudoku[0].size(); i++) {
        if(sudoku[row][i] == val)
            return false;
        
        if(sudoku[i][col] == val)
            return false;
        
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku) {
    int size = sudoku[0].size();
    for(int i=0; i < size; i++) {
        for(int j=0; j<size; j++) {

            if(sudoku[i][j] == 0) {
                for(int val = 1; val<=9; val++) {
                    if(issafe(i, j, sudoku, val)) {
                        sudoku[i][j] = val;
                        bool furtherpossible = solve(sudoku);

                        if(furtherpossible)
                            return true;
                        else
                            sudoku[i][j] = 0;
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}