/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:

1 <= n <= 8
*/

#include<iostream>
#include <vector>
using namespace std;





// TC : O(ccatlan(n) * n) SC : O(n) catalan(n) = (2nCn) / (n+1)
class Solution {
public: 
    void solve(int n, int open, int close, vector<string>& ans, string cur) {
        if(open == close && close == n) {
            ans.push_back(cur);
            return ;
        }

        if(open < n)
            solve(n, open + 1, close, ans, cur + '(');
        if(close < open)
            solve(n, open, close + 1, ans, cur + ')');

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, 0, 0, ans, "");
        return ans;
    }
};