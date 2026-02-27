#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
    vector<int> v;
    unordered_set<int> s1(a.begin(),a.end());
    unordered_set<int> s2(b.begin(), b.end());

    for (int it : s1) {
        if (s2.find(it) != s2.end()) {
            v.push_back(it);
        }
    }
    return v;
}
int main() {
    vector<int> a = {1, 2, 2, 3, 7, 5};
    vector<int> b = {2, 4, 3, 5};
    vector<int> result = intersectionWithDuplicates(a, b);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}