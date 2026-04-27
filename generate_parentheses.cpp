/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int n, string s, vector<string>& ans, int open, int close) {
        if(open == close && open == n) {
            ans.push_back(s);
            return ;
        }

        if(open < n)
            solve(n, s + "(", ans, open+1, close);
        if(close < open)
            solve(n, s + ")", ans, open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "", ans, 0, 0);

        return ans;
    }
};