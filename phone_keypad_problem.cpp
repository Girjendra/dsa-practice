/*
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string& digits, vector<string>& ans, string& output, string mapping[], int index) {
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    int num = digits[index] - '0';
    string value = mapping[num];
    for(int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, ans, output, mapping, index + 1);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() <= 0)
        return ans;

    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, ans, output, mapping, 0);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    cout << "Possible combinations for \"" << digits << "\":" << endl;
    for(const string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

/*
for digits = "23";
solve(index = 0, output = "")
├── Add 'a' → solve(index = 1, output = "a")
│   ├── Add 'd' → solve(index = 2, output = "ad") → PUSH "ad"
│   ├── Add 'e' → solve(index = 2, output = "ae") → PUSH "ae"
│   └── Add 'f' → solve(index = 2, output = "af") → PUSH "af"
├── Add 'b' → solve(index = 1, output = "b")
│   ├── Add 'd' → solve(index = 2, output = "bd") → PUSH "bd"
│   ├── Add 'e' → solve(index = 2, output = "be") → PUSH "be"
│   └── Add 'f' → solve(index = 2, output = "bf") → PUSH "bf"
└── Add 'c' → solve(index = 1, output = "c")
    ├── Add 'd' → solve(index = 2, output = "cd") → PUSH "cd"
    ├── Add 'e' → solve(index = 2, output = "ce") → PUSH "ce"
    └── Add 'f' → solve(index = 2, output = "cf") → PUSH "cf"
*/