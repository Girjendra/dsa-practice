#include<bits/stdc++.h>
using namespace std;
// TC = O(2^(n1+n2))
// SC = O(n1+n2)
int solve(string a, string b, int i, int j) {
    if(i >= a.size() || j >= b.size())
        return 0;
        
    if(a[i] == b[j])
        return 1 + solve(a, b, i+1, j+1);
    else
        return max(solve(a, b, i+1, j), solve(a, b, i, j+1));
}
int longestCommonSubsequence(string text1, string text2) {
    return solve(text1, text2, 0, 0);
}






// TC = O(n1*n2)
// SC = O(n1*n2)
int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
    if(i >= a.size() || j >= b.size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solve(a, b, i+1, j+1, dp);
    else
        ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
    
    dp[i][j] = ans;
    return ans;
}
int longestCommonSubsequence(string a, string b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    return solve(a, b, 0, 0, dp);
}







// TC = O(n1*n2)
// SC = O(n1*n2)
int solve(string& a, string& b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i = n1-1; i >= 0; i--) {
        for(int j = n2-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + dp[i+1][j+1];
            else
                ans = max(dp[i+1][j], dp[i][j+1]);
            
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int longestCommonSubsequence(string a, string b) {
    return solve(a, b);
}






// TC = O(n1*n2)
// SC = O(n2)
int solve(string& a, string& b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> cur(n2+1, 0);
    vector<int> next(n2+1, 0);
    
    for(int i = n1-1; i >= 0; i--) {
        for(int j = n2-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + next[j+1];
            else
                ans = max(next[j], cur[j+1]);
            
            cur[j] = ans;
        }
        next = cur;
    }
    return next[0];
}
int longestCommonSubsequence(string a, string b) {
    return solve(a, b);
}