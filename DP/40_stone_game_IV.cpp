/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(2^n) SC : O(n)
class Solution {
public:
    int solve(int n){
        if(n == 0)
            return false;

        for(int root = 1; root * root <= n; root++)
            if(!solve(n - root * root))
                return true;

        return false;
    }

    bool winnerSquareGame(int n) {
        return solve(n);
    }
};

// TC : O(n * sqrt(n)) SC : O(n)
class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0)
            return false;

        if(dp[n] != -1)  
            return dp[n];

        for(int root = 1; root * root <= n; root++)
            if(!solve(n - root * root, dp))
                return dp[n] = true;

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};