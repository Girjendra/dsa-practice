#include<bits/stdc++.h>
using namespace std;
// TC = O(2^n)
// SC = O(n)
int sumofelem(vector<int>& arr) {
    int a = 0;
    for(int it : arr)
        a += it;
    return a;
}
int solve(vector<int>& arr, int tar, int sum, int i) {
    if(tar == sum)
        return 1;
    if(tar < sum || i >= arr.size())
        return 0;
    
    int in = solve(arr, tar, sum+arr[i], i+1);
    if(in)
        return 1;
    
    int ex = solve(arr, tar, sum, i+1);
    if(ex)
        return 1;
    
    return 0;
}
bool equalPartition(vector<int>& arr) {
    int sum = sumofelem(arr);
    if(sum % 2 == 1)
        return 0;    
    return solve(arr, sum/2, 0, 0);
}




// TC = O(n*sum)
// SC = O(n*sum)
int sumofelem(vector<int>& arr) {
    int a = 0;
    for(int it : arr)
        a += it;
    return a;
}
int solve(vector<int>& arr, int tar, int sum, int i, vector<vector<int>>& dp) {
    if(tar == sum)
        return 1;
    if(tar < sum || i >= arr.size())
        return 0;
    
    if(dp[i][sum] != -1)
        return dp[i][sum];
        
    int in = solve(arr, tar, sum+arr[i], i+1, dp);
    int ex = solve(arr, tar, sum, i+1, dp);
    
    if(in || ex ) {
        dp[i][sum] = 1;
        return 1;
    }
    
    dp[i][sum] = 0;
    return 0;
}
bool equalPartition(vector<int>& arr) {
    int sum = sumofelem(arr);
    if(sum % 2 == 1)
        return 0;

    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));
    return solve(arr, sum/2, 0, 0, dp);
}




// TC = O(n*sum)
// SC = O(n*sum)
int sumofelem(vector<int>& arr) {
    int a = 0;
    for(int it : arr)
        a += it;
    return a;
}
int solve(vector<int>& arr) {
    int n = arr.size();
    int sum = sumofelem(arr);
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
        
    for(int i = n-1; i >= 0; i--) {
        for(int tar = 0; tar <= sum/2; tar++) {
            int in = 0;
            if(tar-arr[i] >= 0)
                in = dp[i+1][tar-arr[i]];
            int ex = dp[i+1][tar];
            
            dp[i][tar] = in || ex;
        }
    }
    return dp[0][sum/2];
}
bool equalPartition(vector<int>& arr) {
    int sum = sumofelem(arr);
    if(sum % 2 == 1)
        return 0;
        
    return solve(arr);
}





// TC = O(n*sum)
// SC = O(sum)
int sumofelem(vector<int>& arr) {
    int a = 0;
    for(int it : arr)
        a += it;
    return a;
}
int solve(vector<int>& arr) {
    int n = arr.size();
    int sum = sumofelem(arr);

    vector<int> prev(sum+1, 0);
    vector<int> cur(sum+1, 0);
    
    prev[0] = 1;
    cur[0] = 1;
        
    for(int i = n-1; i >= 0; i--) {
        for(int tar = 0; tar <= sum/2; tar++) {
            int in = 0;
            if(tar-arr[i] >= 0)
                in = prev[tar-arr[i]];
            int ex = prev[tar];
            
            cur[tar] = in || ex;
        }
        prev = cur;
    }
    return prev[sum/2];
}
bool equalPartition(vector<int>& arr) {
    int sum = sumofelem(arr);
    if(sum % 2 == 1)
        return 0;
        
    return solve(arr);
}