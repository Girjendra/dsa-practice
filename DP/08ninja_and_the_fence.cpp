#include <bits/stdc++.h> 
using namespace std;
# define MOD 1000000007
// TC - O(2^n)
// SC - O(n) (recursion stack)
int solve(int n, int k) {
    if(n == 1)
        return k;
    if(n == 2)
        return k*k;

    int ans = (k-1)*solve(n-1, k) + (k-1)*solve(n-2, k);
    return ans;
}

int numberOfWays(int n, int k) {
    return solve(n, k);
}




// TC - O(n)
// SC - O(n) (dp array)
int add(int a, int b) {
    return (a%MOD + b%MOD) % MOD;
}
int mul(int a, int b) {
    return ((a%MOD)*1LL*(b%MOD)) % MOD;
}
int solve(int n, int k, vector<int>& dp) {
    if(n == 1)
        return k;
    if(n == 2)
        return add(k, mul(k, k-1));

    if(dp[n] != -1)
        return dp[n];

    int ans = add(mul(k-1, solve(n-1, k, dp)), mul(k-1, solve(n-2, k, dp)));

    dp[n] = ans;
    return ans;
}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    return solve(n, k, dp);
}




#include <bits/stdc++.h> 
# define MOD 1000000007
// TC - O(n)
// SC - O(n) (dp array)
int add(int a, int b) {
    return (a%MOD + b%MOD) % MOD;
}
int mul(int a, int b) {
    return ((a%MOD)*1LL*(b%MOD)) % MOD;
}
int solve(int n, int k) {
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));;

    for(int i = 3; i <= n; i++) {
        dp[i] = add(mul(k-1, dp[i-1]), mul(k-1, dp[i-2]));
    }
    
    return dp[n];
}
int numberOfWays(int n, int k) {
    return solve(n, k);
}



#include <bits/stdc++.h> 
# define MOD 1000000007
// TC - O(n)
// SC - O(1)
int add(int a, int b) {
    return (a%MOD + b%MOD) % MOD;
}
int mul(int a, int b) {
    return ((a%MOD)*1LL*(b%MOD)) % MOD;
}
int solve(int n, int k) {
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));;

    for(int i = 3; i <= n; i++) {
        int cur = add(mul(k-1, prev1), mul(k-1, prev2));
        prev2 = prev1;
        prev1 = cur;
    }
    
    return prev1;
}
int numberOfWays(int n, int k) {
    return solve(n, k);
}