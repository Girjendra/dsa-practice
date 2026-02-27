#include <iostream>
#include <vector>
using namespace std;
int countFreq(vector<int>& arr, int target) {
    int n = arr.size();
    int st = 0;
    int end = n - 1;
    int mid;

    while (st <= end) {
        mid = st + (end - st) / 2;

        if (arr[mid] == target) {
            int si = mid;
            int ei = mid;

            while (si - 1 >= 0 && arr[si - 1] == target) {
                si--;
            }
            while (ei + 1 < n && arr[ei + 1] == target) {
                ei++;
            }
            return (ei - si + 1);
        }

        if (arr[mid] > target) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return 0;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int freq = countFreq(arr, target);
    cout << "Frequency of " << target << " is: " << freq << endl;
    return 0;
}
