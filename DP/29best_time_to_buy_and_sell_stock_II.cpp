#include<bits/stdc++.h>
using namespace std;
// TC = O(2^n) SC = O(n)
int solve(vector<int>& p, int i, int buy) {
    if(i == p.size())
        return 0;

    int pro = 0;
    if(buy) {
        pro = max((-p[i]) + solve(p, i+1, 0), solve(p, i+1, 1));
    }
    else {
        pro = max((p[i]) + solve(p, i+1, 1), solve(p, i+1, 0));
    }
    return pro;
}
int maxProfit(vector<int>& prices) {
    return solve(prices, 0, 1);
}







// TC = O(n) SC = O(n)
int solve(vector<int>& p, int i, int buy, vector<vector<int>>& dp) {
    if(i == p.size())
        return 0;

    if(dp[i][buy] != -1)
        return dp[i][buy];

    int pro = 0;
    if(buy) {
        pro = max((-p[i]) + solve(p, i+1, 0, dp), solve(p, i+1, 1, dp));
    }
    else {
        pro = max((p[i]) + solve(p, i+1, 1, dp), solve(p, i+1, 0, dp));
    }
    dp[i][buy] = pro;
    return pro;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}








// TC = O(n) SC = O(n)
int solve(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            int pro = 0;
            if(buy) {
                pro = max((-p[i]) + dp[i+1][0], dp[i+1][1]);
            }
            else {
                pro = max((p[i]) + dp[i+1][1], dp[i+1][0]);
            }
            dp[i][buy] = pro;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int>& prices) {
    return solve(prices);
}








// TC = O(n) SC = O(1)
int solve(vector<int>& p) {
    int n = p.size();
    vector<int> prev(2, 0);
    vector<int> cur(2, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            int pro = 0;
            if(buy) {
                pro = max((-p[i]) + prev[0], prev[1]);
            }
            else {
                pro = max((p[i]) + prev[1], prev[0]);
            }
            cur[buy] = pro;
        }
        prev = cur;
    }
    return prev[1];
}
int maxProfit(vector<int>& prices) {
    return solve(prices);
}