#include <iostream>
#include <vector>
using namespace std;
bool ispossible(vector<int> &arr, int k, int mid) {
    int stucount = 1;
    int pagecount = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (pagecount + arr[i] <= mid) {
            pagecount += arr[i];
        } else {
            stucount++;
            if (stucount > k || arr[i] > mid) {
                return false;
            }
            pagecount = arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int k) {
    int n = arr.size();

    if (k > n)
        return -1;

    int sum = 0;
    for (int it : arr)
        sum += it;

    int s = 0;
    int e = sum;

    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (ispossible(arr, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    // vector<int> arr = {12, 34, 67, 90};
    // int k = 2; // Number of students

    vector<int> arr = {22, 23, 67};
    int k = 1; // Number of students

    int result = findPages(arr, k);
    cout << "Minimum number of pages: " << result << endl;

    return 0;
}