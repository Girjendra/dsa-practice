/*
You are given a binary string s and a positive integer k.

A substring of s is beautiful if the number of 1's in it is exactly k.

Let len be the length of the shortest beautiful substring.

Return the lexicographically smallest beautiful substring of string s with length equal to len. If s doesn't contain a beautiful substring, return an empty string.

A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.

For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.
*/
#include<iostream>
#include <climits>
using namespace std;

// TC = O(n), SC = O(1)
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        int bestLen = INT_MAX;
        string ans = "";

        for(int right = 0; right < n; right++) {

            if(s[right] == '1')
                ones++;

            // We have more than k ones
            while(ones > k) {
                if(s[left] == '1')
                    ones--;
                left++;
            }

            if(ones == k) {

                // Remove unnecessary zeros from left
                while(left <= right && s[left] == '0')
                    left++;

                int len = right - left + 1;

                string cur = s.substr(left, len);

                if(len < bestLen) {
                    bestLen = len;
                    ans = cur;
                }
                else if(len == bestLen && cur < ans) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};