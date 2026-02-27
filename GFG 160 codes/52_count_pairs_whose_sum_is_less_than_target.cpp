/*
Given an array arr[] and an integer target. You have to find the number
of pairs in the array whose sum is strictly less than the target.
*/


// O(n^2)
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int countPairs(vector<int> arr,int target){
//     int count = 0;

//     for (int i = 0; i < arr.size()-1; i++){
//         for (int j = i+1; j < arr.size(); j++){
//         if(arr[i]+arr[j]<target)
//             count++;
//         }

//     }
//     return count;
// }
// int main() {
// 	vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
//     int target = 7;
//     cout << countPairs(arr, target);
//     return 0;
// }




// Two pointer approach O(n*logn+n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairs(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int count = 0;
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum < target) {
            count += j - i;
            i++;
        } else {
            j--;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
    int target = 7;
    cout << countPairs(arr, target);
    return 0;
}