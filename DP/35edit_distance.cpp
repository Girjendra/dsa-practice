#include<bits/stdc++.h>
using namespace std;
// TC = O(3^(n1+n2))
// SC = O(n1+n2)
int solve(string a, string b, int i, int j) {
    if(i == a.size())
        return b.size() - j;

    if(j == b.size())
        return a.size() - i;

    int ans = 0;
    if(a[i] == b[j])
        return solve(a, b, i+1, j+1);
    else {
        int insert = 1 + solve(a, b, i, j+1);
        int del = 1 + solve(a, b, i+1, j);
        int repl = 1 + solve(a, b, i+1, j+1);
        ans = min(insert, min(del, repl));
    }
    return ans;
}
int minDistance(string a, string b) {
    return solve(a, b, 0, 0);
}



// TC = O(n1*n2)
// SC = O(n1*n2)
int solve(string a, string b, int i, int j, vector<vector<int>>& dp) {
    if(i == a.size())
        return b.size() - j;

    if(j == b.size())
        return a.size() - i;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(a[i] == b[j])
        return solve(a, b, i+1, j+1, dp);
    else {
        int insert = 1 + solve(a, b, i, j+1, dp);
        int del = 1 + solve(a, b, i+1, j, dp);
        int repl = 1 + solve(a, b, i+1, j+1, dp);
        ans = min(insert, min(del, repl));
    }

    dp[i][j] = ans;
    return ans;
}
int minDistance(string a, string b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    return solve(a, b, 0, 0, dp);
}







// TC = O(n1*n2)
// SC = O(n1*n2)
int solve(string a, string b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int j = 0; j < n2; j++)
        dp[n1][j] = n2-j;
    
    for(int i = 0; i < n1; i++)
        dp[i][n2] = n1-i;
    
    for(int i = n1-1; i >= 0; i--) {
        for(int j = n2-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j])
                ans = dp[i+1][j+1];
            else {
                int insert = 1 + dp[i][j+1];
                int del = 1 + dp[i+1][j];
                int repl = 1 + dp[i+1][j+1];
                ans = min(insert, min(del, repl));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int minDistance(string a, string b) {
    return solve(a, b);
}





// TC = O(n1*n2)
// SC = O(n2)
int minDistance(string a, string b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> next(n2 + 1, 0), cur(n2 + 1, 0);
    for (int j = 0; j <= n2; j++)
        next[j] = n2 - j;

    for (int i = n1 - 1; i >= 0; i--) {
        cur[n2] = n1 - i;
        for (int j = n2 - 1; j >= 0; j--) {
            if (a[i] == b[j]) {
                cur[j] = next[j + 1];
            } else {
                int insert = 1 + cur[j + 1];
                int del    = 1 + next[j];
                int repl   = 1 + next[j + 1];
                cur[j] = min(insert, min(del, repl));
            }
        }
        next = cur;
    }
    return next[0];
}