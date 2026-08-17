/*
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's score is initially zero.

Return the maximum score that Alice can obtain.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC : O(2^n*n), SC : O(n) SC : O(n)
class Solution {
public:
    int solve(int l, int r, vector<int>& stoneValue) {
        if(l >= r)
            return 0;

        int ans = 0;

        int leftSum = 0;
        int total = 0;

        for(int i = l; i <= r; i++)
            total += stoneValue[i];

        for(int k = l; k < r; k++) {
            leftSum += stoneValue[k];
            int rightSum = total - leftSum;

            if(leftSum < rightSum) {
                ans = max(ans,
                          leftSum + solve(l, k, stoneValue));
            }
            else if(leftSum > rightSum) {
                ans = max(ans,
                          rightSum + solve(k + 1, r, stoneValue));
            }
            else {
                ans = max(ans,
                          leftSum + max(
                              solve(l, k, stoneValue),
                              solve(k + 1, r, stoneValue)
                          ));
            }
        }

        return ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        return solve(0, stoneValue.size() - 1, stoneValue);
    }
};



// TC : O(n^3), SC : O(n^2)
class Solution {
public:
    int solve(int l, int r, vector<int>& a,
              vector<vector<int>>& dp,
              vector<int>& pref) {

        if(l >= r)
            return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        int total = pref[r + 1] - pref[l];

        for(int k = l; k < r; k++) {

            int leftSum = pref[k + 1] - pref[l];
            int rightSum = total - leftSum;

            if(leftSum < rightSum) {
                ans = max(ans,
                          leftSum + solve(l, k, a, dp, pref));
            }
            else if(leftSum > rightSum) {
                ans = max(ans,
                          rightSum + solve(k + 1, r, a, dp, pref));
            }
            else {
                ans = max(ans,
                          leftSum + max(
                              solve(l, k, a, dp, pref),
                              solve(k + 1, r, a, dp, pref)
                          ));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, stoneValue, dp, pref);
    }
};