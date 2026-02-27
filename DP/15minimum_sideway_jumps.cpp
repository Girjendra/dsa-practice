#include<bits/stdc++.h>
using namespace std;
// TC = O(3^n)
// SC = O(n)
int solve(vector<int>& ob, int lane, int pos) {
    int n = ob.size();
    if(pos == n-1)
        return 0;

    if(ob[pos+1] != lane)
        return solve(ob, lane, pos+1);
    else {
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++) {
            if(lane != i && ob[pos] != i)
                ans = min(ans, 1 + solve(ob, i, pos));
        }
        return ans;
    }
}
int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles, 2, 0);
}



// TC = O(n)
// SC = O(n)
int solve(vector<int>& ob, int lane, int pos, vector<vector<int>>& dp) {
    int n = ob.size();
    if(pos == n-1)
        return 0;

    if(dp[lane][pos] != -1)
        return dp[lane][pos];

    if(ob[pos+1] != lane)
        return solve(ob, lane, pos+1, dp);
    else {
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++) {
            if(lane != i && ob[pos] != i)
                ans = min(ans, 1 + solve(ob, i, pos, dp));
        }
        dp[lane][pos] = ans;
        return ans;
    }
}
int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, -1));
    return solve(obstacles, 2, 0, dp);
}




// TC = O(n)
// SC = O(n)
int solve(vector<int>& ob) {
    int n = ob.size();
    vector<vector<int>> dp(4, vector<int>(n, 1e9));
    dp[1][n-1] = 0;
    dp[2][n-1] = 0;
    dp[3][n-1] = 0;

    for(int pos = n-2; pos >= 0; pos--) {
        for(int lane = 1; lane <=3; lane++) {
            
            if(ob[pos+1] != lane)
                dp[lane][pos] =  dp[lane][pos+1];
            else {
                int ans = 1e9;
                for(int i = 1; i <= 3; i++) {
                    if(lane != i && ob[pos] != i)
                        ans = min(ans, 1 + dp[i][pos+1]);
                }
                dp[lane][pos] = ans;
            }
        }
    }
    return min(dp[2][0], 1 + min(dp[1][0], dp[3][0]));
}
int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles);
}




// TC = O(n)
// SC = O(1)
int solve(vector<int>& ob) {
    int n = ob.size();
    vector<int> cur(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int pos = n-2; pos >= 0; pos--) {
        for(int lane = 1; lane <=3; lane++) {
            
            if(ob[pos+1] != lane)
                cur[lane] =  next[lane];
            else {
                int ans = 1e9;
                for(int i = 1; i <= 3; i++) {
                    if(lane != i && ob[pos] != i)
                        ans = min(ans, 1 + next[i]);
                }
                cur[lane] = ans;
            }
        }
        next = cur;
    }
    return min(next[2], 1 + min(next[1], next[3]));
}
int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles);
}



// TC = O(nlogn)
// SC = O(1)
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int suffixSum = 0;
    int ans = 0;

    for(int i = satisfaction.size() - 1; i >= 0; i--) {
        suffixSum += satisfaction[i];
        if(suffixSum <= 0) break;
        ans += suffixSum;
    }
    return ans;
}