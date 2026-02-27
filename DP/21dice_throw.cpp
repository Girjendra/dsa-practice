#include<bits/stdc++.h>
using namespace std;
// TC = O(f^d)
// SC = O(d)
int solve(int dice, int faces, int tar) {
    if(tar < 0)
        return 0; 
    if(tar == 0 && dice != 0)
        return 0;  
    if(tar == 0 && dice == 0)
        return 1;  
    if(tar != 0 && dice == 0)
        return 0;
        
    int ans = 0;
    for(int i = 1; i <= faces; i++) {
        ans += solve(dice-1, faces, tar-i);
    }
    return ans;
}
int noOfWays(int m, int n, int x) {
    return solve(n , m, x);
}




// TC = O(d*t*f)
// SC = O(d*t)
int solve(int dice, int faces, int tar, vector<vector<int>>& dp) {
    if(tar < 0)
        return 0;
    if(tar == 0 && dice != 0)
        return 0;
    if(tar == 0 && dice == 0)
        return 1;
    if(tar != 0 && dice == 0)
        return 0;
        
    if(dp[dice][tar] != -1)
        dp[dice][tar];
        
    int ans = 0;
    for(int i = 1; i <= faces; i++) {
        ans += solve(dice-1, faces, tar-i, dp);
    }
    return dp[dice][tar] = ans;
}
int noOfWays(int m, int n, int x) {
    vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
    return solve(n , m, x, dp);
}




// TC = O(d*t*f)
// SC = O(d*t)
int solve(int dices, int faces, int target) {
    vector<vector<int>> dp(dices+1, vector<int>(target+1, 0));
    dp[0][0] = 1;
    
    for(int d = 1; d <= dices; d++) {
        for(int t = 1; t <= target; t++) {
            int ans = 0;
            for(int i = 1; i <= faces; i++) {
                if(t-i >= 0)
                    ans += dp[d-1][t-i];
            }
            dp[d][t] = ans;
        }
    }
    return dp[dices][target];
}
int noOfWays(int m, int n, int x) {
    return solve(n , m, x);
}



// TC = O(d*t*f)
// SC = O(t)
int solve(int dices, int faces, int target) {
    vector<int> prev(target+1, 0);
    vector<int> cur(target+1, 0);
    prev[0] = 1;
    
    for(int d = 1; d <= dices; d++) {
        for(int t = 1; t <= target; t++) {
            int ans = 0;
            for(int i = 1; i <= faces; i++) {
                if(t-i >= 0)
                    ans += prev[t-i];
            }
            cur[t] = ans;
        }
        prev = cur;
    }
    return prev[target];
}
int noOfWays(int m, int n, int x) {
    return solve(n , m, x);
}