/*
You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a
subarray whose size is between l and r (inclusive) and whose sum is greater than 0.
Return the minimum sum of such a subarray. If no such subarray exists, return -1.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [3, -2, 1, 4], l = 2, r = 3
Output: 1
Explanation:
The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:
[3, -2] with a sum of 1
[1, 4] with a sum of 5
[3, -2, 1] with a sum of 2
[-2, 1, 4] with a sum of 3
Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer
is 1.

Example 2:
Input: nums = [-2, 2, -3, 1], l = 2, r = 3
Output: -1
Explanation:
There is no subarray of length between l and r that has a sum greater than 0. So, the answer is -1.

Example 3:
Input: nums = [1, 2, 3, 4], l = 2, r = 4
Output: 3
Explanation:
The subarray [1, 2] has a length of 2 and the minimum sum greater than 0. So, the answer is 3.

Constraints:
1 <= nums.length <= 100
1 <= l <= r <= nums.length
-1000 <= nums[i] <= 1000
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;





// TC : O(n*r) SC : O(1)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                if((j - i + 1) > r)
                    break;

                sum += nums[j];
                if(((j - i + 1) >= l) && ((j - i + 1) <= r) && sum > 0)
                    ans = min(ans, sum);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};








// TC : O(n*(r-l)) SC : O(n)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int L, int R) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + L; j <= min(n, i + R); j++) {
                int sum = prefix[j] - prefix[i];
                if (sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};









// TC : O(n*(R-L)) SC : O(1)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int L, int R) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int len = L; len <= R; len++) {

            int sum = 0;
            for (int i = 0; i < len; i++)
                sum += nums[i];

            if (sum > 0)
                ans = min(ans, sum);

            for (int i = len; i < n; i++) {
                sum += nums[i];
                sum -= nums[i - len];

                if (sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};