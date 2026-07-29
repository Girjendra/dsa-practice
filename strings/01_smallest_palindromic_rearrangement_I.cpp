/*
You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.
*/
#include<iostream>
#include <map>
using namespace std;
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        map<char, int> fre;

        for(char ch : s)
            fre[ch]++;

        string ans;

        char och = 'Z';
        if(s.size() % 2) {
            for(auto& it : fre) {
                if(it.second % 2) {
                    och = it.first;
                    it.second--;
                    break;
                }
            }
        }

        for(auto it : fre) {
            int f = it.second;
            char ch = it.first;
            f /= 2;

            while(f) {
                ans.push_back(ch);
                f--;
            }
        }

        if(och != 'Z')
            ans.push_back(och);

        int i;
        if(s.size() % 2)
            i = ans.size() - 1;
        else
            i = ans.size();


        while(i--) {
            ans.push_back(ans[i]);
        }

        return ans;
    }
};