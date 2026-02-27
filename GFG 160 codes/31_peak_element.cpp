#include <iostream>
#include <vector>
using namespace std;
int peakElement(vector<int> &arr) {
    int n = arr.size();
    int index = -1;

    if (n == 1) {
        index = 0;
    }

    if (n > 1 && arr[0] > arr[1]) {
        index = 0;
    }

    if (n > 1 && arr[n - 2] < arr[n - 1]) {
        index = n - 1;
    }

    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            index = i;
        }
    }

    return index;
}
int main() {
    // vector<int> arr = {1, 3, 20, 4, 1};
    vector<int> arr = {-1};

    int peakIdx = peakElement(arr);
    cout << "Peak element index: " << peakIdx << endl;
    cout << "Peak element value: " << arr[peakIdx] << endl;

    return 0;
}