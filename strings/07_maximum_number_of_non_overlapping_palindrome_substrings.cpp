/*
You are given a string s and a positive integer k.

Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.
Example 2:

Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.
 

Constraints:

1 <= k <= s.length <= 2000
s consists of lowercase English letters.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



// TC : O(n^2 + mlogm)
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<pair<int,int>> intervals;

        for(int center = 0; center < n; center++) {
            int l = center;
            int r = center;

            while(l >= 0 && r < n && s[l] == s[r]) {

                if(r - l + 1 >= k)
                    intervals.push_back({l, r});

                l--;
                r++;
            }
        }

        for(int center = 0; center < n - 1; center++) {
            int l = center;
            int r = center + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 >= k)
                    intervals.push_back({l, r});

                l--;
                r++;
            }
        }

        sort(intervals.begin(), intervals.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                if(a.second != b.second)
                    return a.second < b.second;

                return a.first < b.first;
            });

        int ans = 0;
        int lastEnd = -1;

        for(auto [l, r] : intervals) {

            if(l > lastEnd) {
                ans++;
                lastEnd = r;
            }
        }

        return ans;
    }
};