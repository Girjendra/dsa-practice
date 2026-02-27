// // Very unefficient
// #include <iostream>
// #include <string>
// using namespace std;
// string removeDuplicates(string s) {
//     bool flag = true;
//     while (flag) {
//         int i = 0;
//         flag = false;
//         while (i < s.length() - 1 && s.length() != 0){
//             if (s[i] == s[i + 1]) {
//                 s.erase(i, 2);
//                 flag = true;
//                 break;
//             }
//             else
//                 i++;
//         }
//     }
//     return s;
// }

// int main() {
//     string str = "azxxzy";
//     cout << "Original string: " << str << endl;
//     string result = removeDuplicates(str);
//     cout << "After removing duplicates: " << result << endl;
//     return 0;
// }




// Very efficient
#include <iostream>
#include <string>
using namespace std;
    string removeDuplicates(string s) {
        string result = "";
        for (char ch : s) {
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
int main() {
    string str = "azxxzy";
    cout << "Original string: " << str << endl;
    string result = removeDuplicates(str);
    cout << "After removing duplicates: " << result << endl;
    return 0;
}
