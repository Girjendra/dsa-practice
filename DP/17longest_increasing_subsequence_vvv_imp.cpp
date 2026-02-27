#include<bits/stdc++.h>
using namespace std;
// TC = O(2^n)
// SC = O(n)
int solve(vector<int>& arr, int n, int cur, int prev) {
    if(cur == n)
        return 0;
        
    int in = 0;
    if(prev == -1 || arr[cur] > arr[prev])
        in = 1 + solve(arr, n, cur+1, cur);
    
    int ex = 0 + solve(arr, n, cur+1, prev);
    return max(in, ex);
}
int lis(vector<int>& arr) {
    int n = arr.size();
    return solve(arr, n, 0, -1);
}




// TC = O(n^2)
// SC = O(n^2) + O(n) for recursion stack
int solve(vector<int>& arr, int n, int cur, int prev, vector<vector<int>>& dp) {
    if(cur == n)
        return 0;
    
    if(dp[cur][prev+1] != -1)
        return dp[cur][prev+1];
        
    int in = 0;
    if(prev == -1 || arr[cur] > arr[prev]) {
        in = 1 + solve(arr, n, cur+1, cur, dp);
    }
    
    int ex = 0 + solve(arr, n, cur+1, prev, dp);
    
    dp[cur][prev+1] = max(in, ex);
    return dp[cur][prev+1];
}
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(arr, n,0, -1, dp);
}





// TC = O(n^2)
// SC = O(n^2)
int solve(vector<int>& arr, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int cur = n-1; cur >= 0; cur--) {
        for(int prev = cur-1; prev >= -1; prev--) {
            int in = 0;
            if(prev == -1 || arr[cur] > arr[prev]) {
                in = 1 + dp[cur+1][cur+1];
            }
            
            int ex = 0 + dp[cur+1][prev+1];
            
            dp[cur][prev+1] = max(in, ex);
        }
    }
    return dp[0][0];
}
int lis(vector<int>& arr) {
    int n = arr.size();
    return solve(arr, n);
}




// TC = O(n^2)
// SC = O(n)
int solve(vector<int>& arr, int n) {
vector<int> current(n+1, 0);
vector<int> next(n+1, 0);
    
    for(int cur = n-1; cur >= 0; cur--) {
        for(int prev = cur-1; prev >= -1; prev--) {
            int in = 0;
            if(prev == -1 || arr[cur] > arr[prev]) {
                in = 1 + next[cur+1];
            }
            
            int ex = 0 + next[prev+1];
            
            current[prev+1] = max(in, ex);
        }
        next = current;
    }
    return next[0];
}
int lis(vector<int>& arr) {
    int n = arr.size();
    return solve(arr, n);
}




// TC = O(n log n)
// SC = O(n)
int lis(vector<int>& arr) {
    int n = arr.size();
    
    if(n == 0)
        return 0;
        
    vector<int> ans;
    ans.push_back(arr[0]);
    
    for(int i = 1; i < n; i++) {
        if(arr[i] > ans.back())
            ans.push_back(arr[i]);
        else {
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}