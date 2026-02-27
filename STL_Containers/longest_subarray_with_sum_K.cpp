#include<bits/stdc++.h>
using namespace std;

// Works only for +ve vlaues
// TC = O(2n) = O(n) Average case
// SC = O(n)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int ans = 0;
    long long cs = a[0];
    int l = 0, r = 0;

    while(r < n) {
        while(l <= r && cs > k) {
            cs -= a[l];
            l++;
        }

        if(cs == k) 
            ans = max(ans, r - l + 1);

        r++;
        if(r < n ) cs += a[r];
    }
    return ans;
}




// Works for both -ve ans +ve values
// TC = O(n) Average case
// Worst-case (very rare, bad hashing): TC = O(n²)
// SC = O(n)
int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int cursum = 0;
    int ans = 0;
    map<int, int> m;
    
    for(int i = 0; i < n; i++) {
        cursum += arr[i];
        
        if(cursum == k)
            ans = i+1;
        
        if(m.find(cursum - k) != m.end())
            ans = max(ans, i - m[cursum - k]);
        
        if(m.find(cursum) == m.end())
            m[cursum] = i;
    }
    
    return ans;
}