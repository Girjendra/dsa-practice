// /*
// Given two strings s1 and s2, return true if s2 contains
// a permutation of s1, or false otherwise.

// In other words, return true if one of s1's
// permutations is the substring of s2.
// */


// // TLE
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;
//     bool checkInclusion(string s1, string s2) {
//       int n = s1.length();
//       sort(s1.begin(),s1.end());
//       do{
//         if(s2.find(s1)!=string::npos){
//             return true;
//         }
//       }while(next_permutation(s1.begin(),s1.end())); 
//       return false;
//     }
// int main() {
//     string s1, s2;
//     cout << "Enter string s1 (pattern): ";
//     cin >> s1;
//     cout << "Enter string s2 (text): ";
//     cin >> s2;

//     if (checkInclusion(s1, s2))
//         cout << s1 << "'s permutation exists in '" << s2 << "'" << endl;
//     else
//         cout << s1 << "'s permutation does not exist in '" << s2 << "'" << endl;
//     return 0;
// }










#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> freq1(26, 0), freq2(26, 0);

    for (char ch : s1) {
        freq1[ch - 'a']++;
    }

    int windowSize = s1.size();
    for (int i = 0; i < s2.size(); i++) {
        freq2[s2[i] - 'a']++;

        if (i >= windowSize)
            freq2[s2[i - windowSize] - 'a']--;

        if (freq1 == freq2) return true;
    }
    return false;
}
int main() {
    string s1, s2;
    cout << "Enter string s1 (pattern): ";
    cin >> s1;
    cout << "Enter string s2 (text): ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << s1 << "'s permutation exists in '" << s2 << "'" << endl;
    } else {
        cout << s1 << "'s permutation does not exist in '" << s2 << "'" << endl;
    }
    return 0;
}
