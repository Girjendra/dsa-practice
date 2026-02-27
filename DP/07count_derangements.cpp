#include<bits/stdc++.h>
using namespace std;
// TC -> O(n!)
// SC -> O(n) recursion stack
long long int solve(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    
    long long int ans = (n-1)*(solve(n-1) + solve(n-2));
    return ans;
}
long long int countDerangements(int n) {
    return solve(n);
}




// TC -> O(n)
// SC -> O(n) + O(n) for dp array
long long int solve(int n, vector<int>& dp) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    long long int ans = ((n-1)*(solve(n-1, dp) + solve(n-2, dp))) % 1000000007;
    dp[n] = ans;
    return ans;
}
long long int countDerangements(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}





// TC -> O(n)
// SC -> O(n) for dp array
long long int solve(int n) {
    vector<long long int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++) {
        dp[i] = ((i-1)*(dp[i-1] + dp[i-2])) % 1000000007;
    }

    return dp[n];
}
long long int countDerangements(int n) {
    return solve(n);
}




// TC -> O(n)
// SC -> O(1)
long long int solve(int n) {
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i = 3; i <= n; i++) {
        long long int cur = ((i-1)*(prev1 + prev2)) % 1000000007;
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}
long long int countDerangements(int n) {
    return solve(n);
}