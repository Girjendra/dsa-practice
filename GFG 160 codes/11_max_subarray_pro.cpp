// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//         vector<int> arr =  {-2, 6, -3, -10, 0, 2};
//         int  n = arr.size();
//         int cmin = arr[0];
//         int cmax = arr[0];
//         int maxpro = arr[0];

//         int temp;
//         for(int i=1;i<n;i++){
//             temp = max(max(arr[i],cmin*arr[i]),cmax*arr[i]);
//             cmin = min(min(arr[i],cmin*arr[i]),cmax*arr[i]);
//             cmax = temp;
//             maxpro = max(maxpro,cmax);
//         }
//         cout<<"Max product is: "<<maxpro<<endl;      // 180
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>  // for max and min
// using namespace std;

// int maxProduct(vector<int>& nums) {
//     int cmax = nums[0];
//     int cmin = nums[0];
//     int maxpro = nums[0];

//     for (int i = 1; i < nums.size(); i++) {
//         if (nums[i] < 0) {
//             swap(cmax, cmin);
//         }

//         cmax = max(nums[i], cmax * nums[i]);
//         cmin = min(nums[i], cmin * nums[i]);
//         maxpro = max(maxpro, cmax);
//     }

//     return maxpro;
// }
// int main() {
//     vector<int> arr = {-2, 6, -3, -10, 0, 2};
//     cout << "Maximum product subarray is: " << maxProduct(arr) << endl;
//     return 0;
// }