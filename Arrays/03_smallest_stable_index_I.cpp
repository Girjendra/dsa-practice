/*
You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:

max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(n) and SC: O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxi(n);
        int cmax = nums[0];
        maxi[0] = nums[0];

        for(int i = 1; i < n; i++) {
            if(cmax < nums[i])
                cmax = nums[i];

            maxi[i] = cmax;
        }

        vector<int> mini(n);
        int cmin = nums[n - 1];
        mini[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            if(cmin > nums[i])
                cmin = nums[i];

            mini[i] = cmin;
        }

        for(int i = 0; i < n; i++) {
            if(maxi[i] - mini[i] <= k)
                return i;
        }

        return -1;
    }
};



// TC : O(n) and SC: O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxi(n);
        int cmax = nums[0];
        maxi[0] = nums[0];

        vector<int> mini(n);
        int cmin = nums[n - 1];
        mini[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            if(cmax < nums[i])
                cmax = nums[i];

            if(cmin > nums[n - i - 1])
                cmin = nums[n - i - 1];

            maxi[i] = cmax;
            mini[n - i - 1] = cmin;
        }

        for(int i = 0; i < n; i++) {
            if(maxi[i] - mini[i] <= k)
                return i;
        }

        return -1;
    }
};



// TC : O(n) and SC: O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return 0;

        vector<int> maxi(n), mini(n);
        int cmax = nums[0], cmin = nums[n - 1];
        maxi[0] = nums[0], mini[n - 1] = nums[n - 1];

        int ans = n;
        for(int i = 1; i < n; i++) {
            if(cmax < nums[i])
                cmax = nums[i];

            if(cmin > nums[n - i - 1])
                cmin = nums[n - i - 1];

            maxi[i] = cmax;
            mini[n - i - 1] = cmin;

            if(n - i - 1 <= i) {
                int leftind = n - i - 1;
                if((maxi[leftind] - mini[leftind]) <= k)
                    ans = min(ans, leftind);

                int rightind = i;
                if((maxi[rightind] - mini[rightind]) <= k)
                    ans = min(ans, rightind);
            }
        }
        
        return ans != n ? ans : -1;
    }
};