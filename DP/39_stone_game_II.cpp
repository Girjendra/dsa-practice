/*
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
*/
#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

// TC : O(n^2 * m) where n is the number of piles and m is the maximum value of M
class Solution {
public:
    int solve(int i, int M, vector<int>& piles, vector<vector<int>>& dp) {
        int n = piles.size();

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int take = 0;
        int ans = 0;

        for (int x = 1; x <= 2 * M && i + x <= n; x++) {
            take += piles[i + x - 1];

            int opponent = solve(i + x, max(M, x), piles, dp);

            ans = max(ans, take + 
                      (accumulate(piles.begin() + i + x, piles.end(), 0)
                       - opponent));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        int total = accumulate(piles.begin(), piles.end(), 0);

        int opponent = solve(0, 1, piles, dp);

        return opponent;
    }
};