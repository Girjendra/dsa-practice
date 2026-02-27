#include <bits/stdc++.h> 
using namespace std;
// TC = O(n^tar)
// SC = O(tar) (dp array)
int solve(vector<int> &num, int tar) {
    if(tar == 0)
        return 1;
    else if(tar < 0)
        int INT_MIN;

    int ans = 0;
    for(int it : num) {
        int n = 0;
        if(it <= tar)
           n = solve(num, tar-it);
        if(n > 0)
            ans += n;
    }
    return ans;
}
int findWays(vector<int> &num, int tar) {
    return solve(num, tar);
}




// TC = O(n*tar)
// SC = O(tar) (dp array)
int solve(vector<int> &num, int tar, vector<int>& dp) {
    if(tar == 0)
        return 1;
    else if(tar < 0)
        int INT_MIN;

    if(dp[tar] != -1)
        return dp[tar];

    int ans = 0;
    for(int it : num) {
        int n = 0;
        if(it <= tar)
           n = solve(num, tar-it, dp);
        if(n > 0)
            ans += n;
    }
    dp[tar] = ans;
    return ans;
}
int findWays(vector<int> &num, int tar) {
    vector<int> dp(tar+1, -1);
    return solve(num, tar, dp);
}



// TC = O(n*tar)
// SC = O(tar) (dp array)
int solve(vector<int> &num, int tar) {
    vector<int> dp(tar+1, 0);
    dp[0] = 1;

    for(int t = 0; t <= tar; t++) {
        for(int it : num) {
            if(t-it >= 0)
            dp[t] += dp[t-it];
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar) {
    return solve(num, tar);
}