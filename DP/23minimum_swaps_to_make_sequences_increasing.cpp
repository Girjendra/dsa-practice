#include<bits/stdc++.h>
using namespace std;
// TC = O(2^N) , SC = O(N)
int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped) {
    if(i == nums1.size())
        return 0;

    int ans = INT_MAX;

    int p1 = nums1[i-1];
    int p2 = nums2[i-1];

    if(swapped)
        swap(p1, p2);
    
    if(nums1[i] > p1 && nums2[i] > p2)
        ans = solve(nums1, nums2, i+1, 0);

    if(nums1[i] > p2 && nums2[i] > p1)
        ans = min(ans, 1 + solve(nums1, nums2, i+1, 1));

    return ans;
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int swapped = 0;
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2, 1, swapped);
}





// TC = O(N) , SC = O(N)
int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped, vector<vector<int>>& dp) {
    if(i == nums1.size())
        return 0;

    if(dp[i][swapped] != -1)
        return dp[i][swapped];

    int ans = INT_MAX;

    int p1 = nums1[i-1];
    int p2 = nums2[i-1];

    if(swapped)
        swap(p1, p2);

    if(nums1[i] > p1 && nums2[i] > p2)
        ans = solve(nums1, nums2, i+1, 0, dp);

    if(nums1[i] > p2 && nums2[i] > p1)
        ans = min(ans, 1 + solve(nums1, nums2, i+1, 1, dp));

    dp[i][swapped] = ans;
    return ans;
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int swapped = 0;
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(nums1, nums2, 1, swapped, dp);
}



// TC = O(N) , SC = O(N)
int solve(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int i = n-1; i >=1; i--) {
        for(int swapped = 1; swapped >= 0; swapped--) {
            int ans = INT_MAX;
            int p1 = nums1[i-1];
            int p2 = nums2[i-1];

            if(swapped)
                swap(p1, p2);

            if(nums1[i] > p1 && nums2[i] > p2)
                ans = dp[i+1][0];

            if(nums1[i] > p2 && nums2[i] > p1) {
                ans = min(ans, 1 + dp[i+1][1]);
            }
            
            dp[i][swapped] = ans;
        }
    }
    return dp[1][0];
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    return solve(nums1, nums2);
}




// TC = O(N) , SC = O(1)
int solve(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> cur(2, 0);
    vector<int> prev(2, 0);

    for(int i = n-1; i >=1; i--) {
        for(int swapped = 1; swapped >= 0; swapped--) {
            int ans = INT_MAX;
            int p1 = nums1[i-1];
            int p2 = nums2[i-1];

            if(swapped)
                swap(p1, p2);

            if(nums1[i] > p1 && nums2[i] > p2)
                ans = prev[0];

            if(nums1[i] > p2 && nums2[i] > p1) {
                ans = min(ans, 1 + prev[1]);
            }

            cur[swapped] = ans;
        }
        prev = cur;
    }
    return prev[0];
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    return solve(nums1, nums2);
}