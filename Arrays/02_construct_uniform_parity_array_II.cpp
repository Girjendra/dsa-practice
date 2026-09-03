/*
You are given an array nums1 of n distinct integers.

You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

For each index i, you must choose exactly one of the following (in any order):

nums2[i] = nums1[i]​​​​​​​
nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
Return true if it is possible to construct such an array, otherwise return false.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;

// TC : O(n) and SC: O(1)
class Solution {
public:
    bool uniformArray(vector<int>& n1) {
        int n = n1.size();

        int minOdd = INT_MAX;
        bool hasOdd = false;

        for(int i = 0; i < n; i++) {
            if(n1[i] % 2) {
                hasOdd = true;
                minOdd = min(minOdd, n1[i]);
            }
        }

        if(!hasOdd)
            return true;

        for(int i = 0; i < n; i++) {
            if(n1[i] % 2 == 0) {
                if(n1[i] <= minOdd)
                    return false;
            }
        }

        return true;
    }
};