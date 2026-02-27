/*
Given an unsorted array of integers, find the number of subarrays
having sum exactly equal to a given number k.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumFreq;
    int count = 0, sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k)
            count++;

        if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[sum - k];
        }
        prefixSumFreq[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 1};
    int k = 3;
    cout <<"Number of subarrays with sum equal to "<<k<<" is: "<< countSubarrays(nums, k) << endl;
    return 0;
}