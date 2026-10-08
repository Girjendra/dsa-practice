/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.


Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

Constraints:
1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.
*/
#include<iostream>
using namespace std;






// TC : O(n) SC : O(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int oc = 0;
        int cc = 0;
        string ans = "";
        int i = 0;
        while(i < s.size()) {
            if(oc == 0 && s[i] == '(') {
                int temp = i + 1;
                while (true) {
                    if(s[temp] == '(')
                        oc++;
                    else
                        cc++;

                    if(cc == oc + 1) {
                        oc = 0;
                        cc = 0;
                        break;
                    }

                    ans += s[temp++];
                }
                
                i = temp + 1;
            }
        }

        return ans;
    }
};