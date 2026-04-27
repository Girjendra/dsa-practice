#include<bits/stdc++.h>
using namespace std;

// Recursion TC = O(n^2) SC = O(n)
int nCr(int n, int r) {
    if(r > n)
        return 0;
        
    if(r == 0 || n == r)
        return 1;
    
    return nCr(n-1, r-1) + nCr(n-1, r);
}

// DP TC = O(n*k) SC = O(n*k)
int solve(int n, int k, vector<vector<int>>& dp) {
    if(k > n)
        return 0;
        
    if(k == 0 || n == k)
        return 1;
    
    if(dp[n][k] != -1)
        return dp[n][k];
    
    return dp[n][k] = (solve(n-1, k-1, dp) + solve(n-1, k, dp));
}
int nCr(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return solve(n, k, dp);
}


int main(){
    int n, k;
    cout << "Enter n and k :" << endl;
    cin >> n >> k;

    cout << "C(" << n << ", " << k << ") = " << nCr(n, k);
    return 0;
}