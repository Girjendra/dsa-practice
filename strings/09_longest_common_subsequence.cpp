/*
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.
A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

Constraints:
1<= s1.size(), s2.size() <=103
Both strings s1 and s2 contain only uppercase English letters.
*/
#include<iostream>
#include <vector>
using namespace std;





// TC : O(2^(m+n)) SC : O(m+n) Recursive Approach
class Solution {
public:
    int solve(int i, int j, string& s1, string& s2) {
        if(i == s1.size() || j == s2.size())
            return 0;

        if(s1[i] == s2[j])
            return 1 + solve(i + 1, j + 1, s1, s2);

        return max(
            solve(i + 1, j, s1, s2),
            solve(i, j + 1, s1, s2)
        );
    }

    int LCS(string& s1, string& s2) {
        return solve(0, 0, s1, s2);
    }
};




// TC : O(m*n) SC : O(m*n) Memoization Approach
class Solution {
public:
    int solve(int i, int j, string& s1, string& s2,
            vector<vector<int>>& dp) {

        if(i == s1.size() || j == s2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] =
                1 + solve(i + 1, j + 1, s1, s2, dp);

        return dp[i][j] = max(
            solve(i + 1, j, s1, s2, dp),
            solve(i, j + 1, s1, s2, dp)
        );
    }

    int LCS(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, s1, s2, dp);
    }
};





// TC : O(m*n) SC : O(m*n) Tabulation Approach
class Solution {
public:
    int LCS(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
            }
        }

        return dp[n][m];
    }
};





// TC : O(m*n) SC : O(2*n) Space Optimized Tabulation Approach
class Solution {
public:
    int LCS(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                if(s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];

                else
                    curr[j] = max(
                        prev[j],
                        curr[j - 1]
                    );
            }

            prev = curr;
        }

        return prev[m];
    }
};