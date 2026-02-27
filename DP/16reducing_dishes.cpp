#include<bits/stdc++.h>
using namespace std;
// TC = O(2^n)
// SC = O(n) for recursion stack
int solve(vector<int>& sat, int n, int i, int time) {
    if(i >= n)
        return 0;
    
    int in = sat[i]*(time+1) + solve(sat, n, i+1, time+1);
    int ex = solve(sat, n, i+1, time);

    return max(in, ex);
}
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, satisfaction.size(), 0, 0);
}




// TC = O(n^2)
// SC = O(n^2) for dp array + O(n) for recursion stack
int solve(vector<int>& sat, int n, int i, int time, vector<vector<int>>& dp) {
    if(i >= n)
        return 0;
    
    if(dp[i][time] != -1)
        return dp[i][time];

    int in = sat[i]*(time+1) + solve(sat, n, i+1, time+1, dp);
    int ex = 0 + solve(sat, n, i+1, time, dp);

    dp[i][time] = max(in, ex);
    return dp[i][time];
}
int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(satisfaction, n, 0, 0, dp);
}




// TC = O(n^2)
// SC = O(n^2) for dp array
int solve(vector<int>& sat) {
    int n = sat.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int time = i; time >= 0; time--) {
            int in = sat[i]*(time+1) + dp[i+1][time+1];
            int ex = 0 + dp[i+1][time];
            dp[i][time] =  max(in, ex);
        }
    }
    return dp[0][0];
}
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction);
}




// TC = O(n^2)
// SC = O(n) for dp array
int solve(vector<int>& sat) {
    int n = sat.size();

    vector<int> cur(n+1, 0);
    vector<int> next(n+1, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int time = i; time >= 0; time--) {
            int in = sat[i]*(time+1) + next[time+1];
            int ex = 0 + next[time];
            cur[time] =  max(in, ex);
        }
        next = cur;
    }
    return next[0];
}
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction);
}