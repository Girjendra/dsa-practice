// #include<iostream>
// #include<vector>
// using namespace std;
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
//     int start = 0;
//     int end = n - 1;
//     int mid = start + (end-start)/2;

//     while (start<=end){
//         if(k==arr[mid]){
//             int i=mid,j=mid;
//             while(i>0&&arr[i-1]==k){
//                 i--;
//             }
//             while(j<n-1&&arr[j+1]==k){
//                 j++;
//             }
//             return {i,j};
//         }

//         if(k<arr[mid]){
//             end = mid - 1;
//         }
//         else{
//             start = mid + 1;
//         }

//         mid = start + (end-start)/2;
//     }
//     return {-1,-1};
// }
// int main(){
//     vector<int> arr = {0,0,1,1,2,2,2,2};
//     pair<int,int> p = firstAndLastPosition(arr,8,2);
//     cout<<"First occurrence: "<<p.first<<endl;
//     cout<<"Last occurrence: "<<p.second<<endl;

//     return 0;
// }




// #include<iostream>
// #include<vector>
// using namespace std;
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     int first = -1, last = -1;

//     // First Occurrence
//     int start = 0, end = n - 1;
//     int mid = start + (end - start) / 2;
//     while (start <= end) {

//         if (arr[mid] == k) {
//             first = mid;
//             end = mid - 1; // keep looking on left side
//         } else if (arr[mid] < k) {
//             start = mid + 1;
//         } else {
//             end = mid - 1;
//         }
//         mid = start + (end - start) / 2;
//     }

//     // Last Occurrence
//     start = 0, end = n - 1;
//     mid = start + (end - start) / 2;
//     while (start <= end) {

//         if (arr[mid] == k) {
//             last = mid;
//             start = mid + 1; // keep looking on right side
//         } else if (arr[mid] < k) {
//             start = mid + 1;
//         } else {
//             end = mid - 1;
//         }
//         mid = start + (end - start) / 2;
//     }

//     return {first, last};
// }
// int main(){
//     vector<int> arr = {0,0,1,1,2,2,2,2};
//     pair<int,int> p = firstAndLastPosition(arr,8,2);
//     cout<<"First occurrence: "<<p.first<<endl;
//     cout<<"Last occurrence: "<<p.second<<endl;

//     return 0;
// }



// Total number of occurrence = (last_inde - firat_index) + 1