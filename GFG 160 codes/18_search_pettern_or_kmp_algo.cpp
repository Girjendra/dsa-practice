// #include <iostream>
// #include <string>
// using namespace std;
// bool isSubstring(const string &mainStr, const string &subStr) {
//     return mainStr.find(subStr) != string::npos;
// }

// int main() {
//     string mainStr = "aabaacaadaabaaba";
//     string subStr = "aaba";

//     if (isSubstring(mainStr, subStr)) {
//         cout << "Yes, it is a substring." << endl;
//     } else {
//         cout << "No, it is not a substring." << endl;
//     }

//     return 0;
// }






// Naive Pattern Matching:Less efficient O(n1*n2)
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// int main() {
//     string txt = "aabaacaadaabaaba";
//     string pat = "aaba";
//         int n1 = txt.length();
//         int n2 = pat.length();

//         vector<int> v;
//         for(int i=0;i<=(n1-n2+1);i++){
//            int j = 0;
//            int count = n2;
//            while(j < n2 &&txt[i+j]==pat[j]){
//                j++;
//            }
//             if(j==count){
//                 v.push_back(i);
//             }
//         }
//         for(int it:v){
//             cout<<it<<" ";
//         }
//     return 0;
// }



// KMP Algorithm (Knuth-Morris-Pratt): more efficient O(n1+n2);
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> search(string& pat, string& txt) {
int m = pat.length();
int n = txt.length();

// Step 1: Build LPS array
vector<int> lps(m, 0);
int len = 0;
for (int i = 1; i < m; ) {
    if (pat[i] == pat[len]) {
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

// Step 2: Search using LPS
vector<int> result;
int i = 0, j = 0;

while (i < n) {
    if (pat[j] == txt[i]) {
        i++;
        j++;
    }

    if (j == m) {
        result.push_back(i - j);
        j = lps[j - 1];
    } else if (i < n && pat[j] != txt[i]) {
        if (j != 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
}
return result;
}
int main(){
    // string s1 = "geeksforgeeks";
    // string s2 = "geek";
    string s1 = "aabaacaadaabaaba";
    string s2 = "aaba";
    vector<int> v = search(s2,s1);
    for(int it:v){
        cout<<it<<" ";
    }
    return 0;
}