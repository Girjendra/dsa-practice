/*
You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land)
that are 4-directionally connected (horizontally or vertically).
The total value of an island is the sum of the values of all cells in the island.
Return the number of islands with a total value divisible by k.

Example 1:
Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
Output: 2
Explanation:
The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted
in red do not.

Example 2:
Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
Output: 6
Explanation:
The grid contains six islands, each with a total value that is divisible by 3.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
0 <= grid[i][j] <= 106
1 <= k <= 106
*/
#include<iostream>
#include <vector>
using namespace std;





// TC : O(m*n) SC O(m*n)
class Solution {
public:
    long long countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j] || vis[i][j])
                    continue;

                if(((long long)solve(grid, vis, i, j)) % k == 0)
                    ans++;

            }
        }

        return ans;
    }

    long long solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j] == 1)
            return 0;

        vis[i][j] = 1;
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        long long ans = 0;
        for(auto it : dir) {
            int ni = i + it[0];
            int nj = j + it[1];
            ans += solve(grid, vis, ni, nj);
        }

        return ans + grid[i][j];
    }
};