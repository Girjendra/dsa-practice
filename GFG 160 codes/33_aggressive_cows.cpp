#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(vector<int> &stalls, int k, int mid) {
    int cowcount = 1;
    int lastpos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastpos >= mid) {
            cowcount++;
            if (cowcount == k) {
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();

    int st = 0;
    int end = stalls[n - 1] - stalls[0];
    
    int ans = -1;
    int mid = st + (end - st) / 2;
    while (st <= end) {
        if (ispossible(stalls, k, mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = st + (end - st) / 2;
    }
    return ans;
}

int main() {
    vector<int> stalls = {2, 12, 11, 3, 26, 7};
    int k = 5;
    int result = aggressiveCows(stalls, k);
    cout << "Largest minimum distance: " << result << endl;
    return 0;
}