/*
Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int solve(int i, vector<int>& sv, vector<int>& dp) {
        int n = sv.size();
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int one = INT_MIN, two = INT_MIN, three = INT_MIN;

        one = sv[i] - solve(i+1, sv, dp);
        if(i+1 < n)
            two = sv[i] + sv[i+1] - solve(i+2, sv, dp);
        if(i+2 < n)    
            three = sv[i] + sv[i+1] + sv[i+2] - solve(i+3, sv, dp);

        return dp[i] = max(max(one, two), three);
    }

    string stoneGameIII(vector<int>& sv) {
        vector<int> dp(sv.size(), -1);
        int ans = solve(0, sv, dp);

        if(ans > 0)
            return "Alice";
        else if(ans < 0)
            return "Bob";
        else
            return "Tie";
    }
};