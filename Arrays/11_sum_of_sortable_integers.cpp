/*
You are given an integer array nums of length n.
An integer k is called sortable if k divides n and you can sort nums in non-decreasing order by sequentially performing the following operations:
Partition nums into consecutive subarrays of length k.
Cyclically rotate each subarray independently any number of times to the left or to the right.
Return an integer denoting the sum of all possible sortable integers k.

Example 1:
Input: nums = [3,1,2]
Output: 3
Explanation:​​​​​​​
For n = 3, possible divisors are 1 and 3.
For k = 1: each subarray has one element. No rotation can sort the array.
For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
Only k = 3 is sortable. Hence, the answer is 3.

Example 2:
Input: nums = [7,6,5]
Output: 0
Explanation:
For n = 3, possible divisors are 1 and 3.
For k = 1: each subarray has one element. No rotation can sort the array.
For k = 3: the single subarray [7, 6, 5] cannot be rotated into non-decreasing order.
No k is sortable. Hence, the answer is 0.

Example 3:
Input: nums = [5,8]
Output: 3
Explanation:​​​​​​​
For n = 2, possible divisors are 1 and 2.
Since [5, 8] is already sorted, every divisor is sortable. Hence, the answer is 1 + 2 = 3.

Constraints:
1 <= n == nums.length <= 105
1 <= nums[i] <= 105
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;







// TC : O(n^2) SC : O(n)
class Solution {
public:
    bool isRotation(vector<int>& a, vector<int>& b, int l, int r) {
        int k = r - l + 1;
        for(int shift = 0; shift < k; shift++) {
            bool ok = true;
            for(int j = 0; j < k; j++) {
                if(a[l + j] != b[l + (j + shift) % k]) {
                    ok = false;
                    break;
                }
            }

            if(ok)
                return true;
        }

        return false;
    }

    bool check(int k, vector<int>& nums, vector<int>& sorted) {
        int n = nums.size();
        for(int l = 0; l < n; l += k) {
            int r = l + k - 1;
            if(!isRotation(nums, sorted, l, r))
                return false;
        }

        return true;
    }

    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;
        for(int k = 1; k * k <= n; k++) {
            if(n % k != 0)
                continue;

            if(check(k, nums, sorted))
                ans += k;

            int other = n / k;
            if(other != k && check(other, nums, sorted))
                ans += other;
        }

        return ans;
    }
};