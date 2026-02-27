// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> mergeOverlap(vector<vector<int>> &arr){
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> res;

//     // Checking for all possible overlaps
//     for (int i = 0; i < n; i++) {
//         int start = arr[i][0];
//         int end = arr[i][1];

//         // Skipping already merged intervals
//         if (!res.empty() && res.back()[1] >= end)
//             continue;

//         // Find the end of the merged range
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j][0] <= end)
//                 end = max(end, arr[j][1]);
//         }
//         res.push_back({start, end});
//     }
//     return res;
// }
// int main() {
//     vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
//     vector<vector<int>> res = mergeOverlap(arr);

//     for (auto interval : res)
//         cout << interval[0] << " " << interval[1] << endl;
//     return 0;
// }



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> mergeOverlap(vector<vector<int>>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());

    vector<vector<int>>  res;
    res.push_back(arr[0]);
        
    for(int i=1;i<n;i++){

        vector<int>& last = res.back();
        vector<int>& curr = arr[i];
            
        if(curr[0]<=last[1])
            last[1] = max(last[1],curr[1]);
        else
            res.push_back(curr);
    }
    return res;
}
int main(){
    vector<vector<int>>  arr = {
       {1,3},{2,4},{6,8},{9,10}
    };
    sort(arr.begin(),arr.end());
    vector<vector<int>> arr2 = mergeOverlap(arr);
    for (int i = 0; i < arr2.size(); i++){
        for (int j = 0; j < 2; j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}




// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int mergeOverlap(vector<vector<int>>& arr){
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     int resIdx = 0; 
//     for (int i = 1; i < n; i++) {
//         if (arr[resIdx][1] >= arr[i][0])           
//             arr[resIdx][1] = max(arr[resIdx][1], arr[i][1]);
//         else{            
//             resIdx++;
//             arr[resIdx] = arr[i];
//         }
//     }
//     return (resIdx + 1);
// }
// int main(){
//     vector<vector<int>>  arr = {
//        {1,3},
//        {2,4},
//        {6,8},
//        {9,10}
//     };
//     int newsize = mergeOverlap(arr);

//     for (int i = 0; i < newsize; i++){
//         for (int j = 0; j < 2; j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }