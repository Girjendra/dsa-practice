// NOT Optimized
// #include<iostream>
// #include<vector>
// using namespace std;
// int inversionCount(vector<int> &arr) {
//     int n = arr.size();
//     int count = 0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// int main(){
//     vector<int> arr = {2, 4, 1, 3, 5};
//     cout<<"Number of inversions: "<<inversionCount(arr)<<endl;
//     return 0;
// }



// Optimized code
// #include <iostream>
// #include <vector>
// using namespace std;
// int countAndMerge(vector<int>& arr,int s,int e) {
//     int mid = s+(e-s)/2;

//     int l1 = mid-s+1;
//     int l2 = e-mid;

//     vector<int> left(l1);
//     vector<int> right(l2);
//     int arrindex = s;

//     for (int i = 0; i < l1; i++)
//         left[i] = arr[arrindex++];
       
//     arrindex = mid+1;
//     for (int j = 0; j < l2; j++)
//         right[j] = arr[arrindex++];

//     int res = 0;
//     arrindex = s;
//     int i = 0, j = 0;
//     while (i < l1 && j < l2) {
//         if (left[i] <= right[j]){
//             arr[arrindex++] = left[i++];
//         }
//         else{
//             arr[arrindex++] = right[j++];
//             res += (l1 - i);
//         }
//     }

//     while (i < l1)
//         arr[arrindex++] = left[i++];

//     while (j < l2)
//         arr[arrindex++] = right[j++];

//     return res;
// }
// int countInv(vector<int>& arr, int s, int e){
//     int res = 0;
//     if (s >= e)
//         return res;

//     int mid = (e + s) / 2;
//     res += countInv(arr, s, mid);
//     res += countInv(arr, mid + 1, e);

//     res += countAndMerge(arr, s, e);
//     return res;
// }
// int main(){
//     // vector<int> arr = {4, 5, 2, 1};
//     vector<int> arr = {2,4,1,3,5};
//     int n = arr.size();
//     cout << countInv(arr,0,n-1)<<endl;

//     for(int it:arr)
//         cout<<it<<" ";
//     return 0;
// }