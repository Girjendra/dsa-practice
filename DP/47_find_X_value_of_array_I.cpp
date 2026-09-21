/*
You are given an array of positive integers nums, and a positive integer k.

You are allowed to perform an operation once on nums, where in each operation you can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty.

You need to find the x-value of nums, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x when divided by k.

Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1.

A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

Note that the prefix and suffix to be chosen for the operation can be empty.


Constraints:
1 <= nums[i] <= 109
1 <= nums.length <= 105
1 <= k <= 5
*/
#include<iostream>
#include <vector>
using namespace std;




// TC : O(n * k), SC: O(k)
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int x : nums) {
            vector<long long> ndp(k, 0);

            // Start a new subarray with x
            ndp[x % k]++;

            // Extend previous subarrays
            for(int r = 0; r < k; r++) {
                int nr = (r * (x % k)) % k;
                ndp[nr] += dp[r];
            }

            // All subarrays ending at current position
            for(int r = 0; r < k; r++)
                ans[r] += ndp[r];

            dp = ndp;
        }

        return ans;
    }
};