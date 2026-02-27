#include <iostream>
#include <vector>
using namespace std;
int minelemindex(vector<int>& arr) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e) {
        if (arr[mid] > arr[e]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int search(vector<int>& arr, int key) {
    int n = arr.size();
    int minindex = minelemindex(arr);
    int s, e;

    if (key >= arr[minindex] && key <= arr[n - 1]) {
        s = minindex;
        e = n - 1;
    } else {
        s = 0;
        e = minindex - 1;
    }

    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int key = 1;

    int result = search(arr, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
