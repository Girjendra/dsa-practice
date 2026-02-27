/*
Given an array arr[] of non-negative integers. Find the length of the
longest sub-sequence such that elements in the subsequence are consecutive
integers, the consecutive numbers can be in any order.duplicate elements are allowed.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to return length of longest subsequence of consecutive integers.
int longestConsecutive(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int count = 1;
    int maxlen = 1;

    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] == arr[i] + 1 || arr[i + 1] == arr[i]) {
            if (arr[i + 1] != arr[i])
                count++;
            maxlen = max(maxlen, count);
        } else {
            count = 1;
        }
    }
    return maxlen;
}

int main() {
    vector<int> arr = {1, 9, 3, 10, 4, 20, 2, 2, 3};
    cout << "Length of the longest consecutive subsequence is "
         << longestConsecutive(arr) << endl;
    return 0;
}