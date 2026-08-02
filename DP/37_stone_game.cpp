/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(2^n) SC: O(n) 
class Solution {
public:
    int solve(int i, int j, vector<int>& p, bool isalice) {
        if(i > j)
            return 0;

        if(isalice) {
            int left = p[i] + solve(i+1, j, p, false);
            int right = p[j] + solve(i, j-1, p, false);

            return max(left, right);
        }
        else {
            int left = p[i] + solve(i+1, j, p, true);
            int right = p[j] + solve(i, j-1, p, true);

            return max(left, right);
        }
    }
    bool stoneGame(vector<int>& piles) {
        return solve(0, piles.size()-1, piles, true) >= 0;
    }
};





// TC : O(n^2) SC: O(n^2)
class Solution {
public:
    int solve(int i, int j, vector<int>& p, bool isalice, vector<vector<int>>& dp) {
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(isalice) {
            int left = p[i] - solve(i+1, j, p, false, dp);
            int right = p[j] - solve(i, j-1, p, false, dp);

            return dp[i][j] = max(left, right);
        }
        else {
            int left = p[i] - solve(i+1, j, p, true, dp);
            int right = p[j] - solve(i, j-1, p, true, dp);

            return dp[i][j] = max(left, right);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, piles.size()-1, piles, true, dp) > 0;
    }
};