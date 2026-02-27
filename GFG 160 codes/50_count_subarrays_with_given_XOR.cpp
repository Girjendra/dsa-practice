/*
Given an array of integers arr[] and a number k, count the
number of subarrays having XOR of their elements as k.
*/

// O(n^2)
// #include<bits/stdc++.h>
// using namespace std;
// int subarrayXor(vector<int>& arr,int k){
//     int res = 0;
//     for (int i = 0; i < arr.size(); i++){
//         int XOR = 0;
//         for (int j = i; j < arr.size(); j++){
//             XOR^=arr[j];

//             if(XOR == k)
//                 res++;
//         }
//     }
//     return res;
// }
// int main() {
//     vector<int> arr = { 4, 2, 2, 6, 4 };
//     int k = 6;

//     cout <<"Number of counts is: " <<subarrayXor(arr, k);
//     return 0;
//  }





// O(n)
// #include <bits/stdc++.h>
// using namespace std;
// int subarrayXor(vector<int> &arr, int k)
// {
//     unordered_map<int, int> m;
//     int res = 0;
//     int xor_count = 0;

//     for (int it : arr)
//     {
//         xor_count ^= it;

//         if (xor_count == k)
//             res++;

//         if (m.find(xor_count ^ k) != m.end())
//         {
//             res += m[xor_count ^ k];
//         }

//         m[xor_count]++;
//     }
//     return res;
// }
// int main()
// {
//     vector<int> arr = {4, 2, 2, 6, 4};
//     int k = 6;

//     cout << "Number of counts is: " << subarrayXor(arr, k);
//     return 0;
// }