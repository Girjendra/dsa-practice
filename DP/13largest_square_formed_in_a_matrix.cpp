#include <bits/stdc++.h>
using namespace std;
// // TC -> O(3^(n*m))
// // SC -> O(n+m) for recursion stack
int solve(vector<vector<int>> &mat, int i, int j, int &maxi) {
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    int bottom = solve(mat, i + 1, j, maxi);
    int left = solve(mat, i, j + 1, maxi);
    int dia = solve(mat, i + 1, j + 1, maxi);

    if (mat[i][j] == 1){
        int ans = 1 + min(bottom, min(left, dia));
        maxi = max(maxi, ans);
        return ans;
    }
    else
        return 0;
}
int maxSquare(vector<vector<int>> &mat) {
    int maxi = 0;
    solve(mat, 0, 0, maxi);
    return maxi;
}




// TC -> O(n*m)
// SC -> O(n*m) for dp array + O(n+m) for recursion stack
int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp) {
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int bottom = solve(mat, i + 1, j, maxi, dp);
    int left = solve(mat, i, j + 1, maxi, dp);
    int dia = solve(mat, i + 1, j + 1, maxi, dp);

    if (mat[i][j] == 1) {
        dp[i][j] = 1 + min(bottom, min(left, dia));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
        return 0;
}
int maxSquare(vector<vector<int>> &mat) {
    int maxi = 0;
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
    solve(mat, 0, 0, maxi, dp);
    return maxi;
}




// TC -> O(n*m)
// SC -> O(n*m) for dp array
int solve(vector<vector<int>> &mat) {
    int maxi = 0;
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for (int i = row - 1; i >= 0; i--) {
        for (int j = col - 1; j >= 0; j--) {
            int bottom = dp[i + 1][j];
            int left = dp[i][j + 1];
            int dia = dp[i + 1][j + 1];

            if (mat[i][j] == 1) {
                dp[i][j] = 1 + min(bottom, min(left, dia));
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi;
}
int maxSquare(vector<vector<int>> &mat) {
    return solve(mat);
}




// TC -> O(n*m)
// SC -> O(m) for two 1D arrays
int solve(vector<vector<int>> &mat) {
    int maxi = 0;
    int row = mat.size();
    int col = mat[0].size();

    vector<int> cur(col + 1, 0);
    vector<int> next(col + 1, 0);

    for (int i = row - 1; i >= 0; i--) {
        for (int j = col - 1; j >= 0; j--) {
            int right = cur[j + 1];
            int dia = next[j + 1];
            int down = next[j];

            if (mat[i][j] == 1) {
                cur[j] = 1 + min(down, min(right, dia));
                maxi = max(maxi, cur[j]);
            }
            else
                cur[j] = 0;
        }
        next = cur;
    }
    return maxi;
}
int maxSquare(vector<vector<int>> &mat) {
    return solve(mat);
}