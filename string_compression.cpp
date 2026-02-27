#include <iostream>
#include <vector>
#include <string>
using namespace std;
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int ansindex = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }
            chars[ansindex++] = chars[i];
            int count = j - i;
            if (count > 1) {
                string s = to_string(count);
                for (char ch : s) {
                    chars[ansindex++] = ch;
                }
            }
            i = j;
        }
        return ansindex;
    }
int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);
    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;
    cout << "New length: " << newLength << endl;
    return 0;
}
