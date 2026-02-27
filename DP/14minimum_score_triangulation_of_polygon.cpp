#include <bits/stdc++.h>
using namespace std;
// TC = O(2^n)
// SC = O(n) for recursion stack
int solve(vector<int> &v, int i, int j) {
    if (i + 1 == j)
        return 0;

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++) {
        ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k) + solve(v, k, j));
    }
    return ans;
}
int minScoreTriangulation(vector<int> &values) {
    return solve(values, 0, values.size() - 1);
}

// TC = O(n^3)
// SC = O(n^2) for dp array + O(n) for recursion stack
int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp) {
    if (i + 1 == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++) {
        ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k, dp) + solve(v, k, j, dp));
    }
    dp[i][j] = ans;
    return ans;
}
int minScoreTriangulation(vector<int> &values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(values, 0, n - 1, dp);
}



// TC = O(n^3)
// SC = O(n^2) for dp array
int solve(vector<int> &v) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 2; j < n; j++) {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                ans = min(ans, v[i] * v[k] * v[j] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}
int minScoreTriangulation(vector<int> &values) {
    return solve(values);
}