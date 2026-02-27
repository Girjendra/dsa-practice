/*
Given valid mathematical expressions in the form of a string.
You are supposed to return true if the given expression contains
a pair of redundant brackets, else return false. The given string
only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

Note :
A pair of brackets is said to be redundant when a subexpression is surrounded
by needless/ useless brackets.

For Example :
((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last
index is needless. While (a + (b*c)) does not have any pair of redundant brackets. 
*/

// O(n) O(n)
#include <bits/stdc++.h> 
using namespace std;
bool findRedundantBrackets(string &s){
    stack<char> st;
    for( int i=0;i<s.length();i++) {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            if(ch == ')') {
                bool flag = true;
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                        flag = false;
                    st.pop();
                }
                if(flag == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

int main() {
    vector<string> testCases = {
        "((a+b))",
        "(a+(b*c))",
        "(a+b*(c-d))",
        "((a))",
        "(a+b)+(c+d)",
        "a+(b)",
        "a+b"
    };

    for (auto& expr : testCases) {
        cout << "Expression: " << expr << " -> ";
        if (findRedundantBrackets(expr)) {
            cout << "Redundant brackets found" << endl;
        } else {
            cout << "No redundant brackets" << endl;
        }
    }

    return 0;
}