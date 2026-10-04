/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true
Example 4:

Input: s = "("
Output: false

Constraints:
1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/
#include<iostream>
#include <vector>
#include <stack>
using namespace std;





// TC : O(3^n) SC : O(n)
class Solution {
public:
    bool solve(int i, string& s, int opencount, int closecount) {
        if(closecount > opencount)
            return false;

        if(i == s.size())
            return opencount == closecount;

        int temp = i;
        while(temp < s.size() && s[temp] != '*') {
            if(s[temp] == '(')
                opencount++;
            else
                closecount++;
            
            if(opencount < closecount)
                return false;

            temp++;
        }

        if(temp == s.size())
            return opencount == closecount;

        i = temp;

        bool op = solve(i + 1, s, opencount + 1, closecount);
        bool cp = solve(i + 1, s, opencount, closecount + 1);
        bool empty = solve(i + 1, s, opencount, closecount);

        return (op || cp || empty);
    }

    bool checkValidString(string s) {
        return solve(0, s, 0, 0);
    }
};





// TC : O(n^3) SC : O(n^3)
class Solution {
public:
    bool solve(int i, string& s, int open, int close, vector<vector<vector<int>>>& dp) {
        // Invalid prefix
        if(close > open)
            return false;

        // End of string
        if(i == s.size())
            return open == close;

        // Already calculated
        if(dp[i][open][close] != -1)
            return dp[i][open][close];

        int temp = i;
        // Process normal parentheses until '*'
        while(temp < s.size() && s[temp] != '*') {

            if(s[temp] == '(')
                open++;
            else
                close++;

            if(close > open)
                return false;

            temp++;
        }

        // No '*' left
        if(temp == s.size())
            return open == close;

        // '*' -> '('
        bool op = solve(temp + 1, s, open + 1, close, dp);
        // '*' -> ')'
        bool cp = solve(temp + 1, s, open, close + 1, dp);
        // '*' -> ""
        bool empty = solve(temp + 1, s, open, close, dp);

        return dp[i][open][close] = (op || cp || empty);
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solve(0, s, 0, 0, dp);
    }
};







// TC : O(n^2) SC : O(n^2)
class Solution {
public:
    bool solve(int i, string& s, int balance, vector<vector<int>>& dp) {
        // Invalid prefix
        if(balance < 0)
            return false;

        // End of string
        if(i == s.size())
            return balance == 0;

        // Already calculated
        if(dp[i][balance] != -1)
            return dp[i][balance];

        // '('
        if(s[i] == '(')
            return dp[i][balance] = solve(i + 1, s, balance + 1, dp);

        // ')'
        if(s[i] == ')')
            return dp[i][balance] = solve(i + 1, s, balance - 1, dp);


        // '*' -> '('
        bool op = solve(i + 1, s, balance + 1, dp);
        // '*' -> ')'
        bool cp = solve(i + 1, s, balance - 1, dp);
        // '*' -> ''
        bool empty = solve(i + 1, s, balance, dp);

        return dp[i][balance] = op || cp || empty;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, s, 0, dp);
    }
};








// TC : O(n) SC : O(n)
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                open.push(i);
            else if(s[i] == '*')
                star.push(i);
            else {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }

        while(!open.empty() && !star.empty()) {
            if(open.top() < star.top()) {
                open.pop();
                star.pop();
            } else {
                return false;
            }
        }

        return open.empty();
    }
};