/*
You are given a 2D integer array grid of size m * n.
You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).
At each step, you may move either right or down.
The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including
the start and end cells.

Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).

Example 1:
Input: grid = [[1,2],[3,4]]
Output: 6
Explanation:
There are two valid paths:
(0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
(0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6
The minimum XOR value among all valid paths is 6.

Example 2:
Input: grid = [[6,7],[5,8]]
Output: 9
Explanation:
There are two valid paths:
(0, 0) → (0, 1) → (1, 1) with XOR: 6 XOR 7 XOR 8 = 9
(0, 0) → (1, 0) → (1, 1) with XOR: 6 XOR 5 XOR 8 = 11
The minimum XOR value among all valid paths is 9.

Example 3:
Input: grid = [[2,7,5]]
Output: 0
Explanation:
There is only one valid path:
(0, 0) → (0, 1) → (0, 2) with XOR: 2 XOR 7 XOR 5 = 0
The XOR value of this path is 0, which is the minimum possible.

Constraints:
1 <= m == grid.length <= 1000
1 <= n == grid[i].length <= 1000
m * n <= 1000
0 <= grid[i][j] <= 1023​
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;







// TC : O(2^(m+n)) SC: O(m+n)
class Solution {
public:
    vector<int> solve(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if(i == m - 1 && j == n - 1)
            return {grid[i][j]};

        vector<int> ans;

        if(j + 1 < n) {
            vector<int> right = solve(grid, i, j + 1);

            for(int x : right)
                ans.push_back(grid[i][j] ^ x);
        }

        if(i + 1 < m) {
            vector<int> down = solve(grid, i + 1, j);

            for(int x : down)
                ans.push_back(grid[i][j] ^ x);
        }

        return ans;
    }

    int minCost(vector<vector<int>>& grid) {
        vector<int> values = solve(grid, 0, 0);
        return *min_element(values.begin(), values.end());
    }
};








// TC : O(1024 × m × n) SC: O(1024 × m × n)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        dp[0][0][grid[0][0]] = true;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                for(int x = 0; x < 1024; x++) {

                    if(!dp[i][j][x])
                        continue;

                    if(j + 1 < n) {
                        int newXor = x ^ grid[i][j + 1];
                        dp[i][j + 1][newXor] = true;
                    }

                    if(i + 1 < m) {
                        int newXor = x ^ grid[i + 1][j];
                        dp[i + 1][j][newXor] = true;
                    }
                }
            }
        }

        for(int x = 0; x < 1024; x++) {
            if(dp[m - 1][n - 1][x])
                return x;
        }

        return -1;
    }
};