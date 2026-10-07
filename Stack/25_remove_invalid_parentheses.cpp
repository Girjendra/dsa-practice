/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:
Input: s = ")("
Output: [""]

Constraints:
1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.
*/
#include<iostream>
#include <vector>
#include <set>
using namespace std;






// TC : O(2^(p*n)) p <= 20, n <= 25 SC : O(n) + O(2^(p*n)) p <= 20, n <= 25
class Solution {
public:

    bool isValid(string &s) {
        int balance = 0;

        for(char ch : s) {
            if(ch == '(')
                balance++;
            else if(ch == ')') {
                balance--;

                if(balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void solve(int i, string &s, string &curr, int removed, int minRemove, set<string> &ans) {

        if(removed > minRemove)
            return;

        if(i == s.size()) {
            if(removed == minRemove && isValid(curr))
                ans.insert(curr);

            return;
        }

        // Letter -> always keep
        if(s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);

            solve(i + 1, s, curr, removed, minRemove, ans);

            curr.pop_back();
        }
        else {
            // Choice 1: Keep this parenthesis
            curr.push_back(s[i]);

            solve(i + 1, s, curr, removed, minRemove, ans);

            curr.pop_back();

            // Choice 2: Remove this parenthesis
            solve(i + 1, s, curr, removed + 1, minRemove, ans);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        // Find minimum removals required
        int balance = 0;
        int minRemove = 0;

        for(char ch : s) {
            if(ch == '(') {
                balance++;
            }
            else if(ch == ')') {
                if(balance > 0)
                    balance--;
                else
                    minRemove++;
            }
        }

        // Remaining unmatched '(' must also be removed
        minRemove += balance;

        set<string> ans;
        string curr = "";

        solve(0, s, curr, 0, minRemove, ans);

        return vector<string>(ans.begin(), ans.end());
    }
};