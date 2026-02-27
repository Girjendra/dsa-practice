// O(n^3)
// #include <iostream>
// #include <vector>
// using namespace std;

// int countTriplets(vector<int> &arr, int target) {
//     int n = arr.size();
//     int res = 0;

//     for (int i = 0; i < n - 2; i++) {
//         for(int j=i+1;j<n-1;j++){
//             for(int k=j+1;k<n;k++){
//                 int sum = arr[i]+arr[j]+arr[k];
//                 if(sum == target)
//                     res++;
//             }
//         }
//     }
//     return res;
// }
// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int target = 15;
//     int result = countTriplets(arr, target);
//     cout << "Number of triplets with sum " << target << " is: " << result << endl;
//     return 0;
// }



// Optimized in O(n^2)
#include <iostream>
#include <vector>
using namespace std;

int countTriplets(vector<int> &arr, int target) {
    int n = arr.size();
    int res = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        while (left < right) {

            int sum = arr[i] + arr[left] + arr[right];

            if (sum < target) {
                left += 1;
            }
            else if (sum > target) {
                right -= 1;
            }
            else if (sum == target) {
                int ele1 = arr[left], ele2 = arr[right];
                int cnt1 = 0, cnt2 = 0;

                while (left <= right && arr[left] == ele1) {
                    left++;
                    cnt1++;
                }

                while (left <= right && arr[right] == ele2) {
                    right--;
                    cnt2++;
                }

                if (ele1 == ele2)
                    res += (cnt1 * (cnt1 - 1)) / 2;
                else
                    res += (cnt1 * cnt2);
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // example sorted array
    int target = 15; // example target sum
    int result = countTriplets(arr, target);
    cout << "Number of triplets with sum " << target << " is: " << result << endl;
    return 0;
}
