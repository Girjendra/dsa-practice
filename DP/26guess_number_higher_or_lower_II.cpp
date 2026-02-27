#include<bits/stdc++.h>
using namespace std;
// TC = O(2^n)
// SC = O(n)
int solve(int st, int end) {
    if(st >= end)
        return 0;
    if(end - st == 1)
        return st;
    
    int ans = INT_MAX;
    for(int i = st; i <= end; i++)
        ans = min(ans, i + max(solve(st, i-1), solve(i+1, end)));
    
    return ans;
}
int getMoneyAmount(int n) {
    return solve(1, n);
}





// TC = O(n^3)
// SC = O(n^2)
int solve(int st, int end, vector<vector<int>> dp) {
    if(st >= end)
        return 0;
    if(end - st == 1)
        return st;

    if(dp[st][end] != -1)
        return dp[st][end];

    int ans = INT_MAX;
    for(int i = st; i <= end; i++)
        ans = min(ans, i + max(solve(st, i-1, dp), solve(i+1, end, dp)));
    
    dp[st][end] = ans;
    return ans;
}
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(1, n, dp);
}







// TC = O(n^3)
// SC = O(n^2)
int solve(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    
    for(int st = n; st >= 1; st--) {
        for(int end = st; end <= n; end++) {
            if(st == end)
                continue;
            else {
                int ans = INT_MAX;
                for(int i = st; i <= end; i++) {
                    ans = min(ans, i + max(dp[st][i-1], dp[i+1][end]));
                }
                dp[st][end] = ans;
            }
        }
    }
    return dp[1][n];
}
int getMoneyAmount(int n) {
    return solve(n);
}