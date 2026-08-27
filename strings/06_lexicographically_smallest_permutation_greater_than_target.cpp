/*
You are given two strings s and target, both having length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(n + 26) = O(n), where n is the length of the string s. The time complexity is linear with respect to the length of the input string s, as we iterate through the characters of s and target once, and perform constant-time operations for each character. The additional operations related to counting characters and constructing the result string are also linear in terms of the number of unique characters (which is constant at 26 for lowercase English letters).
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string res;
        int n = target.size();
        for (int i = 0; i < n; i++) {
            int targetChar = target[i] - 'a';

            // Case 1: First try to place the same character as target[i] at the
            // current position
            if (cnt[targetChar] > 0) {
                cnt[targetChar]--;
                // Check if the remaining characters can form a string greater
                // than target[i+1:]
                if (canFormGreater(cnt, target, i + 1)) {
                    res.push_back(target[i]);
                    continue;
                }
                // Cannot form a larger string, backtrack
                cnt[targetChar]++;
            }

            // Case 2: Place a character greater than target[i] at the current
            // position
            for (int j = targetChar + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    res.push_back('a' + j);
                    // Fill remaining positions with the smallest
                    // lexicographical order
                    res += getMinString(cnt);
                    return res;
                }
            }

            // No feasible solution found, return directly
            return "";
        }

        return "";
    }

private:
    // Check if the remaining characters can form a string greater than the
    // suffix.
    bool canFormGreater(const vector<int>& cnt, const string& target,
                        int start) {
        string maxStr = getMaxString(cnt);
        string suffix = target.substr(start);
        return maxStr > suffix;
    }

    // Get the maximum lexicographical string (in descending order)
    string getMaxString(const vector<int>& cnt) {
        string res;
        for (int i = 25; i >= 0; i--) {
            res.append(cnt[i], 'a' + i);
        }
        return res;
    }

    // Get the lexicographically smallest string (in ascending order)
    string getMinString(const vector<int>& cnt) {
        string res;
        for (int i = 0; i < 26; i++) {
            res.append(cnt[i], 'a' + i);
        }
        return res;
    }
};