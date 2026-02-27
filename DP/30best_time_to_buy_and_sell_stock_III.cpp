#include<bits/stdc++.h>
using namespace std;
// TC = O(2^n), SC = O(n)
int solve(vector<int>& p, int i, int buy, int count) {
    if(i == p.size() || count >= 2)
        return 0;

    int pro = 0;
    if(buy) {
        pro = max(-p[i] + solve(p, i+1, 0, count), solve(p, i+1, 1, count));
    }
    else {
        pro = max(p[i] + solve(p, i+1, 1, count+1), solve(p, i+1, 0, count));
    }
    return pro;
}
int maxProfit(vector<int>& p) {
    return solve(p, 0, 1, 0);
}





// TC = O(n), SC = O(n)
int solve(vector<int>& p, int i, int buy, int count, vector<vector<vector<int>>>& dp) {
    if(i == p.size() || count == 2)
        return 0;
    if(dp[i][buy][count] != -1)
        return dp[i][buy][count];

    int pro = 0;
    if(buy) {
        pro = max(-p[i] + solve(p, i+1, 0, count, dp), solve(p, i+1, 1, count, dp));
    }
    else {
        pro = max(p[i] + solve(p, i+1, 1, count+1, dp), solve(p, i+1, 0, count, dp));
    }

    dp[i][buy][count] = pro;
    return pro;
}
int maxProfit(vector<int>& p) {
    int n = p.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
    return solve(p, 0, 1, 0, dp);

}






// TC = O(n), SC = O(n)
int solve(vector<int>& p) {
    int n = p.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int count = 1; count >= 0; count--) {
                int pro = 0;
                if(buy) {
                    pro = max(-p[i] + dp[i+1][0][count], dp[i+1][1][count]);
                }
                else {
                    pro = max(p[i] + dp[i+1][1][count+1], dp[i+1][0][count]);
                }

                dp[i][buy][count] = pro;
            }
        }
    }
    return dp[0][1][0];
}
int maxProfit(vector<int>& p) {
    return solve(p);

}





// TC = O(n), SC = O(1)
int solve(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int count = 1; count >= 0; count--) {
                int pro = 0;
                if(buy) {
                    pro = max(-p[i] + next[0][count], next[1][count]);
                }
                else {
                    pro = max(p[i] + next[1][count+1], next[0][count]);
                }

                cur[buy][count] = pro;
            }
            next = cur;
        }
    }
    return next[1][0];
}
int maxProfit(vector<int>& p) {
    return solve(p);
}