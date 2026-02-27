/*
Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called
valid if all the brackets are balanced. Formally for each opening bracket, there
must be a closing bracket right to it.

For Example:
“{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
Ninja wants to make ‘STR’ valid by performing some operations on it.
In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.

Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.

For Example:
Minimum operations to make ‘STR’ =  “{{“ valid is 1.
In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’.
The ‘STR’ now becomes "{}" which is a valid string.

Note:
Return -1 if it is impossible to make ‘STR’ valid.
*/

#include <bits/stdc++.h> 
using namespace std;
int findMinimumCost(string str) {

    // If string has odd length
    if(str.length()%2 == 1)
        return -1;

    stack<char> s;
    for(int i=0;i<str.length();i++) {
        char ch = str[i];
        if(ch == '{') {
            s.push(ch);
        }
        else {
            if(!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(ch);
            }

    }

    // Now the stack contains only unmatched brackets
    int open = 0, close = 0;
    while(!s.empty()) {
        if(s.top() == '{') open++;
        else close++;
        s.pop();
    }

    // Minimum operations formula
    return (open + 1) / 2 + (close + 1) / 2;
}

int main() {
    vector<string> testCases = {
        "{{}}",      // valid, cost 0
        "{{",        // needs 1 change
        "}{}",       // needs 1 change
        "{{}{}}",    // valid, cost 0
        "{}}{{}",    // needs 2 changes
        "{{}}}{",    // needs 1 change
        "}{",        // needs 2 changes
        "{{{{",      // needs 2 changes
        "}}}}",      // needs 2 changes
        "{}{}{}{}",  // valid, cost 0
        "{",         // impossible, -1
        "}",         // impossible, -1
        ""           // valid, cost 0
    };

    for (const auto& test : testCases) {
        cout << "Input: \"" << test << "\" -> Minimum Cost: " << findMinimumCost(test) << endl;
    }
    return 0;
}