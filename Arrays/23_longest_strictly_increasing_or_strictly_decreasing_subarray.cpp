/*
You are given an array of integers nums. Return the length of the longest subarray of nums which is either
strictly increasing or strictly decreasing.


Example 1:
Input: nums = [1,4,3,3,2]
Output: 2
Explanation:
The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
Hence, we return 2.

Example 2:
Input: nums = [3,3,3,3]
Output: 1
Explanation:
The strictly increasing subarrays of nums are [3], [3], [3], and [3].
The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
Hence, we return 1.

Example 3:
Input: nums = [3,2,1]
Output: 3
Explanation:
The strictly increasing subarrays of nums are [3], [2], and [1].
The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
Hence, we return 3.


Constraints:
1 <= nums.length <= 50
1 <= nums[i] <= 50
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;







// TC : O(n^3) SC : O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i = 1; i < n; i++) {
            for(int j = i; j < n; j++) {
                int c1 = 1, c2 = 1;
                for(int k = i; k <= j; k++) {
                    if(nums[k - 1] < nums[k])
                        c1++;
                    else
                        c1 = 1;

                    if(nums[k - 1] > nums[k])
                        c2++;
                    else
                        c2 = 1;
                }
                
                ans = max(ans, max(c1, c2));
            }
        }

        return ans;
    }
};









// TC : O(n) SC : O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        int c1 = 1;
        int c2 = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] < nums[i])
                c1++;
            else {
                ans = max(ans, c1);
                c1 = 1;
            }

            if(nums[i - 1] > nums[i])
                c2++;
            else {
                ans = max(ans, c2);
                c2 = 1;
            }
        }

        ans = max(ans, max(c1, c2));
        return ans;
    }
};