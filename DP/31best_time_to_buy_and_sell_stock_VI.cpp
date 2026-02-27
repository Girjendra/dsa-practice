#include<bits/stdc++.h>
using namespace std;
// TC = O(n*k), SC = O(k)
int solve(vector<int>& p, int k) {
    int n = p.size();
    vector<vector<int>> next(2, vector<int>(k+1, 0));
    vector<vector<int>> cur(2, vector<int>(k+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int count = k-1; count >= 0; count--) {
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
int maxProfit(int k, vector<int>& p) {
    return solve(p, k);        
}




// // TC = O(2^n), SC = O(n)
int solve(int index, int operationNo, int k, vector<int>& prices) {
    if (index == prices.size())
        return 0;

    if (operationNo == 2 * k)
        return 0;

    int profit = 0;
    if (operationNo % 2 == 0) {
        // Buy allowed
        int buyKaro = -prices[index] + solve(index + 1, operationNo + 1, k, prices);
        int skipKaro = solve(index + 1, operationNo, k, prices);
        profit = max(buyKaro, skipKaro);
    }
    else {
        // Sell allowed
        int sellKaro = prices[index] + solve(index + 1, operationNo + 1, k, prices);
        int skipKaro = solve(index + 1, operationNo, k, prices);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}
int maxProfit(int k, vector<int>& prices) {
    return solve(0, 0, k, prices);
}





// TC = O(n*k), SC = O(k)
int solve(int index, int operationNo, int k, vector<int>& prices,
          vector<vector<int>>& dp) {

    if (index == prices.size() || operationNo == 2 * k)
        return 0;

    if (dp[index][operationNo] != -1)
        return dp[index][operationNo];

    int profit = 0;
    if (operationNo % 2 == 0) {
        // Buy
        int buy = -prices[index] + solve(index + 1, operationNo + 1, k, prices, dp);
        int skip = solve(index + 1, operationNo, k, prices, dp);
        profit = max(buy, skip);
    } else {
        // Sell
        int sell = prices[index] + solve(index + 1, operationNo + 1, k, prices, dp);
        int skip = solve(index + 1, operationNo, k, prices, dp);
        profit = max(sell, skip);
    }
    return dp[index][operationNo] = profit;
}
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return solve(0, 0, k, prices, dp);
}






// TC = O(n*k), SC = O(n*k)
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int index = n - 1; index >= 0; index--) {
        for (int op = 2 * k - 1; op >= 0; op--) {

            if (op % 2 == 0) {
                // Buy
                dp[index][op] = max(
                    -prices[index] + dp[index + 1][op + 1],
                    dp[index + 1][op]
                );
            } else {
                // Sell
                dp[index][op] = max(
                    prices[index] + dp[index + 1][op + 1],
                    dp[index + 1][op]
                );
            }
        }
    }
    return dp[0][0];
}




// TC = O(n*k), SC = O(k)
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();

    vector<int> next(2 * k + 1, 0);
    vector<int> cur(2 * k + 1, 0);

    for (int index = n - 1; index >= 0; index--) {
        for (int op = 2 * k - 1; op >= 0; op--) {

            if (op % 2 == 0) {
                cur[op] = max(
                    -prices[index] + next[op + 1],
                    next[op]
                );
            } else {
                cur[op] = max(
                    prices[index] + next[op + 1],
                    next[op]
                );
            }
        }
        next = cur;
    }
    return next[0];
}