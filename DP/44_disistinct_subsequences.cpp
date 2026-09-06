/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(2^n × m) SC : O(n × m)
class Solution {
public:
    int solve(int i, string& s, string& t, string cur) {
        if(t == cur)
            return 1;

        if(i == s.size() || cur.size() > t.size())
            return 0;

        int skip = solve(i+1, s, t, cur);
        int take = solve(i+1, s, t, cur+s[i]);

        return skip + take;
    }

    int numDistinct(string s, string t) {
        return solve(0, s, t, "");
    }
};



// TC : O(n × m) SC : O(n × m)
class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(j == t.size())
            return 1;

        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        if(s[i] == t[j])
            take = solve(i+1, j+1, s, t, dp);
        
        int skip = solve(i+1, j, s, t, dp);

        return dp[i][j] = skip + take;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(0, 0, s, t, dp);
    }
};