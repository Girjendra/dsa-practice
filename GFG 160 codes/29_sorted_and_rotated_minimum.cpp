#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>& arr) {
    int n = arr.size();
    int st = 0;
    int end = n - 1;
    int mid = st + (end - st) / 2;

    while (st < end) {
        if (arr[mid] > arr[end]) {
            st = mid + 1;
        } else {
            end = mid;
        }
        mid = st + (end - st) / 2;
    }
    return arr[st];
}
int main() {
    vector<int> arr = {4, 5, 6, 7, 1, 2};
    int minimum = findMin(arr);
    cout << "Minimum element is: " << minimum << endl;
    return 0;
}
