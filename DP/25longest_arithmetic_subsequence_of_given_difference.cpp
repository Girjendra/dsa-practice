#include<bits/stdc++.h>
using namespace std;
 // TC = O(N^2)  SC = O(1)
int longestSubsequence(vector<int>& arr, int d) {
    int n = arr.size();  
    int ans = 1;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(d == arr[j] - arr[i]) {
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
    }
    return ans;
}




// TC = O(N)  SC = O(N)
int longestSubsequence(vector<int>& arr, int d) {
    int n = arr.size();
    unordered_map<int, int> dp;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int elem = arr[i] - d;
        int temp = 0;

        if(dp.count(elem))
            temp = dp[elem];
        
        dp[arr[i]] = 1 + temp;
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}