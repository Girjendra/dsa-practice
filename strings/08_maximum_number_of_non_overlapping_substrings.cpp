/*
Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.

Constraints:
1 <= s.length <= 105
s contains only lowercase English letters.
*/
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;



class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int,int>> intervals;
        for(int c = 0; c < 26; c++) {

            if(last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for(int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                if(first[x] < l) {
                    valid = false;
                    break;
                }

                if(last[x] > r) {
                    r = last[x];
                }
            }

            if(valid)
                intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b) {
                return a.second < b.second;
            });

        vector<string> ans;
        int lastEnd = -1;

        for(auto [l, r] : intervals) {
            if(l > lastEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }

        return ans;
    }
};