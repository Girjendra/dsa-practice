#include <bits/stdc++.h>
using namespace std;
// // TC = O(N)
// // SC = O(N) + O(N) for recursion stack
// int solve(vector<int> &cost, int n, vector<int> &dp) {
//     if (n == 0 || n == 1)
//         dp[n] = cost[n];

//     if (dp[n] == -1)
//         dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];

//     return dp[n];
// }

// int minCostClimbingStairs(vector<int> &cost) {
//     vector<int> dp(cost.size(), -1);
//     int ans = min(solve(cost, cost.size() - 1, dp), solve(cost, cost.size() - 2, dp));
//     return ans;
// }





// // TC = O(N)
// // SC = O(N)
// int solve(vector<int> &cost, int n) {
//     vector<int> dp(n, -1);
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     for (int i = 2; i < n; i++){
//         dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//     }

//     return min(dp[n - 1], dp[n - 2]);
// }

// int minCostClimbingStairs(vector<int> &cost) {
//     int n = cost.size();
//     return solve(cost, n);
// }




// // TC = O(N)
// // SC = O(1)
// int solve(vector<int> &cost, int n) {
//     int n1 = cost[1];
//     int n0 = cost[0];

//     for (int i = 2; i < n; i++) {
//         int cur = min(n1, n0) + cost[i];
//         n0 = n1;
//         n1 = cur;
//     }

//     return min(n1, n0);
// }

// int minCostClimbingStairs(vector<int> &cost) {
//     int n = cost.size();
//     return solve(cost, n);
// }