#include<bits/stdc++.h>
using namespace std;
// TC = O(N^3), SC = O(1)
int lengthOfLongestAP(vector<int>& arr) {
    int n = arr.size();
    if(n <= 2)
        return n;
        
    int ans = INT_MIN;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int d = arr[j] - arr[i];
            int count = 2;
            
            int prev = i-1;
            int next = arr[i];
            while(prev >= 0) {
                if(next - arr[prev] == d) {
                    count++;
                    next = arr[prev];
                }
                prev--;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}




// TC = O(n^4), SC = O(n)
int solve(int i, vector<int>& arr, int n, int d) {
    if(i < 0)
        return 0;
        
    int ans = 0;
    for(int j = i - 1; j >= 0; j--) {
        if(arr[i]-arr[j] == d)
            ans = max(ans, 1 + solve(j, arr, n, d));
    }
    
    return ans;
}
int lengthOfLongestAP(vector<int>& arr) {
    int n = arr.size();
    if(n <= 2)
        return n;
    int ans = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = max(ans, 2 + solve(i, arr, n, arr[j]-arr[i]));
        }
    }
    return ans;
}





// TC = O(n^3), SC = O(n^2)
int solve(int i, vector<int>& arr, int n, int d, unordered_map<int, int> dp[]) {
    if(i < 0)
        return 0;
        
    if(dp[i].count(d))
        return dp[i][d];
        
    int ans = 0;
    for(int j = i - 1; j >= 0; j--) {
        if(arr[i]-arr[j] == d)
            ans = max(ans, 1 + solve(j, arr, n, d, dp));
    }
    
    return dp[i][d] = ans;
}
int lengthOfLongestAP(vector<int>& arr) {
    int n = arr.size();
    if(n <= 2)
        return n;
    int ans = 0;
    
    unordered_map<int, int> dp[n+1];
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = max(ans, 2 + solve(i, arr, n, arr[j]-arr[i], dp));
        }
    }
    return ans;
}





// TC = O(n^2), SC = O(n^2)
int lengthOfLongestAP(vector<int>& arr) {
    int n = arr.size();
    if(n <= 2)
        return n;
    int ans = 0;
    
    unordered_map<int, int> dp[n+1];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int d = arr[i] - arr[j];
            int cnt = 1;
            
            if(dp[j].count(d))
                cnt = dp[j][d];
            
            dp[i][d] = 1 + cnt;
            ans = max(ans, dp[i][d]);
        }
    }
    return ans;
}