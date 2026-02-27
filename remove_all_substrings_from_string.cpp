#include <iostream>
#include <string>
using namespace std;
string removeOccurrences(string& s, string part) {
    int n = part.length();
    while (s.find(part) != string::npos) {
        int index = s.find(part);
        s.erase(index, n);
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    removeOccurrences(s, part);
    cout << "Resulting string: " << s << endl;

    return 0;
}
