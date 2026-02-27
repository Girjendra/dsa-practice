// #include<iostream>
// #include<string>
// using namespace std;
// bool isPalindrome(string &s, int i, int j) {
//     while (i < j) {
//         if (s[i] != s[j]) {
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
// int minChar(string &s) {
//     int cnt = 0;
//     int i = s.size() - 1;
//     while (i >= 0 && !isPalindrome(s, 0, i)) {
        
//         i--;
//         cnt++;
//     }
//     return cnt;
// }
// int main(){
//     string s = "adaaacecaaa";
//     cout << minChar(s);  // 8
//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> computeLPS(const string& str) {
    int n = str.length();
    vector<int> lps(n, 0);
    int len = 0;

    for (int i = 1; i < n; ) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int minCharsToMakePalindrome(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = s + "$" + rev;
    vector<int> lps = computeLPS(combined);

    return s.length() - lps.back();
}

int main() {
    // string s;
    // cout << "Enter a string: ";
    // cin >> s;

    string s = "aacecaaaa";
    int result = minCharsToMakePalindrome(s);
    cout << "Minimum characters to add at front to make it palindrome: " << result << endl;

    return 0;
}
