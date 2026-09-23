/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;




//  TC : O(2^n)  SC: O(n)
class Solution {
public:
    int solve(int i, int j, vector<int>& nums, int x) {
        if(x == 0)
            return 0;
        
        if(i > j || x < 0)
            return INT_MAX;
        
        int left = solve(i + 1, j, nums, x - nums[i]);
        
        int right = solve(i, j - 1, nums, x - nums[j]);
        
        int ans = min(left, right);
        
        if(ans == INT_MAX)
            return INT_MAX;
        
        return 1 + ans;
    }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int ans = solve(0, n - 1, nums, x);
        return ans == INT_MAX ? -1 : ans;
    }
};



// TC : O(n)  SC: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for(int num : nums)
            total += num;

        long long target = total - x;

        if(target < 0)
            return -1;

        int i = 0;
        long long sum = 0;
        int longest = -1;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            while(i <= j && sum > target) {
                sum -= nums[i];
                i++;
            }

            if(sum == target)
                longest = max(longest, j - i + 1);
        }

        if(longest == -1)
            return -1;

        return n - longest;
    }
};