/*
You are given an array of positive integers nums.
An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
prod(arr) is the product of all elements of arr.
gcd(arr) is the GCD of all elements of arr.
lcm(arr) is the LCM of all elements of arr.
Return the length of the longest product equivalent subarray of nums.

Example 1:
Input: nums = [1,2,1,2,1,1,1]
Output: 5
Explanation: 
The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2,
gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.

Example 2:
Input: nums = [2,3,4,5,6]
Output: 3
Explanation: 
The longest product equivalent subarray is [3, 4, 5].

Example 3:
Input: nums = [1,2,3,1,4,5,1]
Output: 5

Constraints:
2 <= nums.length <= 100
1 <= nums[i] <= 10
*/
#include<iostream>
#include <vector>
#include <numeric>
using namespace std;








class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long prodVal = nums[i];
            long long gcdVal = nums[i];
            long long lcmVal = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                prodVal = prodVal * nums[j];
                gcdVal = std::gcd(gcdVal, nums[j]);
                lcmVal = std::lcm(lcmVal, nums[j]);
                if (prodVal > gcdVal * lcmVal) {
                    break;
                }
                if (prodVal == gcdVal * lcmVal) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};