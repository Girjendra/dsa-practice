#include<bits/stdc++.h>
using namespace std;
// TC -> O(2^n)
// SC -> O(n) recursion stack
int maxi(vector<int> &nums, int i) {
    if(i < 0)
        return 0;

    if(nums.size() == 1)
        return nums[0];

    int inc = maxi(nums, i-2) + nums[i];
    int exl = maxi(nums, i-1);

    return max(inc, exl);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int size = nums.size();
    return maxi(nums, size-1);
}




// TC -> O(n)
// SC -> O(n) + O(n) for dp array + O(n) recursion stack
int maxi(vector<int> &nums, int i, vector<int>& dp) {
    if(i < 0)
        return 0;

    if(nums.size() == 1)
        return nums[0];

    if(dp[i] != -1)
        return dp[i];
        
    int inc = maxi(nums, i-2, dp) + nums[i];
    int exl = maxi(nums, i-1, dp);
    
    dp[i] = max(inc, exl);
    return dp[i];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int size = nums.size();
    vector<int> dp(size, -1);
    return maxi(nums, size-1, dp);
}



// TC -> O(n)
// SC -> O(n) for dp array
int maxi(vector<int> &nums) {
    int size = nums.size();
    vector<int> dp(size, -1);
    
    dp[0] = nums[0];

    for(int i = 1; i < size; i++) {
        int inc = dp[i-2] + nums[i];
        int exc = dp[i-1] + 0;
        dp[i] = max(inc, exc);
    }

    return dp[size-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    return maxi(nums);
}



// TC -> O(n)
// SC -> O(1)
int maxi(vector<int> &nums) {
    int size = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;

    for(int i = 1; i < size; i++) {
        int inc = prev2 + nums[i];
        int exc = prev1 + 0;
        int cur = max(inc, exc);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    return maxi(nums);
}