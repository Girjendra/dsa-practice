// #include<iostream>
// #include<vector>
// using namespace std;
//     int peakIndexInMountainArray(vector<int>& arr) {
        
//     int start = 0, end = arr.size() - 1;
//     // int max = *max_element(arr.begin(),arr.end());
//     int mid = start + (end - start) / 2;
//     while (start <= end) {

//         if (arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]) {
//             return mid;
//         } else if (arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]){
//             start = mid + 1;
//         } else if(arr[mid]<arr[mid-1]&&arr[mid]>arr[mid+1]) {
//             end = mid;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return mid;
//     }
// int main(){
//     vector<int> arr = {0,1,2,3,5,3,2,1,0};
//     cout<<"Index of paek element is: "<<peakIndexInMountainArray(arr)<<endl;;
//     return 0;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int start = 0, end = arr.size() - 1;

//         while (start < end) {
//             int mid = start + (end - start) / 2;

//             if (arr[mid] < arr[mid + 1]) {
//                 // Peak is towards the right
//                 start = mid + 1;
//             } else {
//                 // Peak is at mid or towards the left
//                 end = mid;
//             }
//         }
//         // At the end, start == end == peak index
//         return start;
//     }
// int main(){
//     vector<int> arr = {0,1,2,3,5,3,2,1,0};
//     cout<<"Index of paek element is: "<<peakIndexInMountainArray(arr)<<endl;;
//     return 0;
// }