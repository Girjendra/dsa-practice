#include <bits/stdc++.h>
using namespace std;
void bucketSort(vector<float>& arr, int n) {
    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (float x : buckets[i]) {
            arr[k++] = x;
        }
    }
}

void printArray(vector<float> arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = arr.size();

    cout << "Before Sorting:\n";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "After Sorting:\n";
    printArray(arr, n);

    return 0;
}
