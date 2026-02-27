#include <bits/stdc++.h>
using namespace std;
// TC = O(2^N)
// SC = O(N) for recursion stack
#include <bits/stdc++.h>
int solve(int nStairs, int i) {
    if(nStairs == i)
        return 1;
    else if(nStairs < i)
        return 0;

    return (solve(nStairs, i+1) + solve(nStairs, i+2)) % 1000000007;
}

int countDistinctWays(int nStairs) {
    return solve(nStairs, 0);
}



// TC = O(N)
// SC = O(N) + O(N) for recursion stack
int solve(int nStairs, vector<int>& dp) {
    if(nStairs == 0 || nStairs == 1)
        return 1;
    if(dp[nStairs] == -1)
        dp[nStairs] = (solve(nStairs-1, dp) + solve(nStairs-2, dp)) % 1000000007;
    else
        return dp[nStairs];
}

int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs+1, -1);
    return solve(nStairs, dp);
}