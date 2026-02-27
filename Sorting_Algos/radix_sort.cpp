#include<bits/stdc++.h>
using namespace std;
void printarr(vector<int> arr) {
    for(int it : arr)
        cout << it << " ";
    cout << endl;
}

void counting_sort(vector<int>& arr, int n, int posi) {
    int k = 10;
    vector<int> count(k, 0);

    for(int it : arr) {
        count[(it/posi) % 10]++;
    }

    for(int i = 1; i < k; i++) {
        count[i] += count[i-1];
    }

    vector<int> b(n);
    for(int i = n-1; i >= 0; i--) {
        b[--count[(arr[i]/posi) % 10]] = arr[i];
    }

    for(int i = 0; i < n; i++) {
        arr[i] = b[i];
    }
}

void radix_sort(vector<int>& arr) {
    int n = arr.size();
    int mx = *max_element(arr.begin(), arr.end());
    for(int exp = 1; mx >= exp; exp *= 10) {
        counting_sort(arr, n, exp);
    }
}

int main(){
    // vector<int> arr = {1,2,6,5,3,8,9,0,1,3,1,6,0,4,7,3,2,6,5,8};
    vector<int> arr = {170, 45, 75, 90, 1000, 987, 24, 2, 66};
    int k = *max_element(arr.begin(), arr.end());
    printarr(arr);
    radix_sort(arr);
    printarr(arr);
    return 0;
}