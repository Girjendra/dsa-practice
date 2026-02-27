// User function template for C++

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int kthMissing(vector<int> &arr, int k) {
    int count = 1;
    int num = 1;
    int i = 1;

    unordered_set<int> s(arr.begin(), arr.end());
    while (count <= k) {
        if (s.find(i) == s.end()) {
            num = i;
            count++;
        }
        i++;
    }
    return num;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k) << endl; // Output: 9
    return 0;
}