/*
You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
#include<iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// TC: O(n^2), SC: O(n)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            map<int, int> m;
            for(int j = i; j < n; j++) {
                m[nums[j]]++;

            bool flag = true;
            for(auto it : m)
                if(it.second > k) {
                    flag = false;
                    break;
                }

            if(flag)
                ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};


// TC: O(n), SC: O(n)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> m;

        int l = 0;
        int ans = 0;

        for(int r = 0; r < n; r++) {
            m[nums[r]]++;

            while(m[nums[r]] > k) {
                m[nums[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};