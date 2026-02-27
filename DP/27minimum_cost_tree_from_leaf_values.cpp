#include<bits/stdc++.h>
using namespace std;
// TC = O(2^n)
// SC = O(n^2)
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right) {
    if(left == right)
        return 0;

    int ans = INT_MAX;
    for(int i = left; i < right; i++) {
        ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
    }
    return ans;
}
int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    map<pair<int, int>, int> maxi;
    for(int i = 0; i < n; i++) {
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j < n; j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve(arr, maxi, 0, n-1);
}






// TC = O(n^3)
// SC = O(n^2)
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {
    if(left == right)
        return 0;
        
    if(dp[left][right] != -1)
        return dp[left][right];

    int ans = INT_MAX;
    for(int i = left; i < right; i++) {
        ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i+1, right, dp));
    }
    dp[left][right] = ans;
    return ans;
}
int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    map<pair<int, int>, int> maxi;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    for(int i = 0; i < n; i++) {
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j < n; j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve(arr, maxi, 0, n-1, dp);
}





// TC = O(n^3)
// SC = O(n^2)
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int left = n-1; left >= 0; left--) {
        for(int right = left; right < n; right++) {

            if(left == right) {
                dp[left][right] = 0;
                continue;
            }
            
            int ans = INT_MAX;
            for(int i = left; i < right; i++) {
                ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
            }
            dp[left][right] = ans;
        }
    }
    return dp[0][n-1];
}
int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    map<pair<int, int>, int> maxi;
    for(int i = 0; i < n; i++) {
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j < n; j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve(arr, maxi);
}