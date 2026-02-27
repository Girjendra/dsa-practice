#include <iostream>
#include <vector>
#include <set>
using namespace std;
// Finding atleast one pair
bool twoSum(vector<int>& arr, int target) {
    int n = arr.size();
    set<int> s(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        int dif = target - arr[i];
        auto it = s.find(dif);
        if (it != s.end() && *it != arr[i])
            return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;
    if (twoSum(arr, target))
        cout << "Pair exists" << endl;
    else
        cout << "Pair does not exist" << endl;
    return 0;
}