#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kthElement(vector<int>& a, vector<int>& b, int k) {
    for(int it : b) {
        a.push_back(it);
    }
    sort(a.begin(), a.end());
    return a[k-1];
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};   // Both a and b are already sorted
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    int result = kthElement(a, b, k);
    cout << "The " << k << "th element is: " << result << endl;

    return 0;
}
