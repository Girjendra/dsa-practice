/*
Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
 
Constraints:
1 <= s.length <= 2000
s consists of lowercase English letters.
*/
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;



// TC : O(2^n) SC : O(n) + O(2^n)
class Solution {
public:
    int MODE = 1e9 + 7;
    int solve(int i, string& s, string cur, unordered_map<string, bool>& m) {
        if(i == s.size()) {
            if(cur != "" && m[cur] == false) {
                m[cur] = true;
                return 1;
            }

            return 0;
        }

        int skip = solve(i+1, s, cur, m);
        int take = solve(i+1, s, cur + s[i], m);

        return (skip + take) % MODE;
    }
    int distinctSubseqII(string s) {
        unordered_map<string, bool> m;

        return solve(0, s, "", m);
    }
};



// TC : O(n) SC : O(1)
class Solution {
public:
    int MODE = 1e9 + 7;
    int distinctSubseqII(string s) {
        vector<long long> last(26, -1);

        long long total = 0;

        for (char ch : s) {
            int ind = ch - 'a';

            if (last[ind] == -1) {
                last[ind] = total;
                total = (2LL * total + 1) % MODE;
            } 
            else {
                long long old = last[ind];
                last[ind] = total;
                total = (2LL * total - old + MODE) % MODE;
            }
        }

        return total;
    }
};