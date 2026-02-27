#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if(s[i] == ')') {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if(s[i] == '}') {
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else if(s[i] == ']') {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
    }
    return true;
}
int main() {
    vector<string> testCases = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "",
        "((({{{[[[]]]}}})))"
    };

    for(const auto& s : testCases) {
        cout << "Input: " << s << " -> ";
        if(isValidParenthesis(s))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}