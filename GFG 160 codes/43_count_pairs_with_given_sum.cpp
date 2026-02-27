// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int countPairs(vector<int> &arr, int target) {
//     unordered_map<int, int> freq;
//     int count = 0;

//     for (int i = 0; i < arr.size(); i++) {
//         int b = target - arr[i];
//         if (freq.find(b) != freq.end()) {
//             count += freq[b];
//         }
//         freq[arr[i]]++;
//     }

//     return count;
// }

// int main() {
//     vector<int> arr = {1, 5, 7, -1, 5};
//     int target = 6;
//     cout << "Count of pairs is " << countPairs(arr, target) << endl;
//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int countpairSum(vector<int> &arr, int n, int target) {
// int left = 0;
//     int right = arr.size() - 1;
//     int count = 0;

//     while (left < right) {
//         int sum = arr[left] + arr[right];

//         if (sum == target) {
//             count++;
//             left++;
//             right--;
//         } else if (sum < target) {
//             left++;
//         } else {
//             right--;
//         }
//     }

//     return (count > 0) ? count : -1;
// }


// int main() {
//     vector<int> arr = {1, 5, 7, -1, 5};
//     int target = 6;
//     cout << "Count of pairs is " << countpairSum(arr,arr.size(),target) << endl;
//     return 0;
// }