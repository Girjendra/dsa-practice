#include <bits/stdc++.h> 
using namespace std;
// TC - O(2^n)
// SC - O(n) (recursion stack)
int solve(vector<int>& weight, vector<int>& value, int i, int maxWeight) {
    if(i == 0) {
        if(weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    int inc = 0;
    if(weight[i] <= maxWeight)
        inc = value[i] + solve(weight, value, i-1, maxWeight-weight[i]);
    
    int exc = 0 + solve(weight, value, i-1, maxWeight);

    return max(inc, exc);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return solve(weight, value, n-1, maxWeight);
}



// TC - O(n*maxWeight)
// SC - O(n*maxWeight) (dp array)
int solve(vector<int>& weight, vector<int>& value, int i, int maxWeight, vector<vector<int>>& dp) {
    if(i == 0) {
        if(weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    if(dp[i][maxWeight] != -1)
        return dp[i][maxWeight];

    int inc = 0;
    if(weight[i] <= maxWeight)
        inc = value[i] + solve(weight, value, i-1, maxWeight-weight[i], dp);
    
    int exc = 0 + solve(weight, value, i-1, maxWeight, dp);

    int ans = max(inc, exc);
    dp[i][maxWeight] = ans;

    return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve(weight, value, n-1, maxWeight, dp);
}



// TC - O(n*maxWeight)
// SC - O(n*maxWeight) (dp array)
int solve(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

    for(int w = weight[0]; w <= maxWeight; w++) {
        if(weight[0] <= w)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for(int i = 1; i < n; i++) {
        for(int w = 0; w <= maxWeight; w++) {
            int inc = 0;
            if(weight[i] <= w)
                inc = value[i] + dp[i-1][w-weight[i]];
            int exc = 0 + dp[i-1][w];

            dp[i][w] = max(inc, exc);           
        }
    }

    return dp[n-1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return solve(weight, value, n, maxWeight);
}




// TC - O(n*maxWeight)
// SC - O(2*maxWeight) (two 1D arrays)
int solve(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<int> prev(maxWeight+1, 0);
    vector<int> cur(maxWeight+1, 0);

    for(int w = weight[0]; w <= maxWeight; w++) {
        if(weight[0] <= w)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for(int i = 1; i < n; i++) {
        for(int w = 0; w <= maxWeight; w++) {
            int inc = 0;
            if(weight[i] <= w)
                inc = value[i] + prev[w-weight[i]];
            int exc = 0 + prev[w];

            cur[w] = max(inc, exc);           
        }
        prev = cur;
    }

    return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return solve(weight, value, n, maxWeight);
}



// TC - O(n*maxWeight)
// SC - O(maxWeight) (one 1D array)
int solve(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<int> cur(maxWeight+1, 0);

    for(int w = weight[0]; w <= maxWeight; w++) {
        if(weight[0] <= w)
            cur[w] = value[0];
        else
            cur[w] = 0;
    }

    for(int i = 1; i < n; i++) {
        for(int w = maxWeight; w >= 0; w--) {  // right to left only
            int inc = 0;
            if(weight[i] <= w)
                inc = value[i] + cur[w-weight[i]];
            int exc = 0 + cur[w];

            cur[w] = max(inc, exc);           
        }
    }
    return cur[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return solve(weight, value, n, maxWeight);
}