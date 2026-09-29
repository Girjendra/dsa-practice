/*
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.


Example 1:
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

Example 2:
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is either '(' or ')'.
*/
#include<bits/stdc++.h>
using namespace std;




// TC : O(2^(m+n)) SC : O(m+n)
class Solution {
public:
    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {
        
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if(i >= m || j >= n)
            return false;

        if(grid[i][j] == '(')
            balance++;
        else
            balance--;

        if(balance < 0)
            return false;

        if(i == m - 1 && j == n - 1)
            return balance == 0;

        return solve(grid, i + 1, j, balance) || solve(grid, i, j + 1, balance);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        return solve(grid, 0, 0, 0);
    }
};



// TC : O(m * n * (m + n)) SC : O(m * n * (m + n))
class Solution {
public:
    bool solve(vector<vector<char>>& grid, int i, int j, int balance, vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n)
            return false;

        if(grid[i][j] == '(')
            balance++;
        else
            balance--;

        if(balance < 0)
            return false;

        int remaining = (m - 1 - i) + (n - 1 - j);

        if(balance > remaining)
            return false;

        if(i == m - 1 && j == n - 1)
            return balance == 0;

        if(dp[i][j][balance] != -1)
            return dp[i][j][balance];

        return dp[i][j][balance] =
            solve(grid, i + 1, j, balance, dp) ||
            solve(grid, i, j + 1, balance, dp);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if((m + n - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return solve(grid, 0, 0, 0, dp);
    }
};