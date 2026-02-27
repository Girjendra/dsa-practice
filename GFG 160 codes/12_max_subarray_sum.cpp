// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
//     int n = arr.size();

//     int totalsum = 0;
//     int currminsum = 0;
//     int currmaxsum = 0;
//     int minsum = arr[0];
//     int maxsum = arr[0];

//     for(int i=0;i<n;i++){
//         currminsum = min(arr[i],arr[i]+currminsum);
//         minsum = min(minsum,currminsum);
            
//         currmaxsum = max(arr[i],arr[i]+currmaxsum);
//         maxsum = max(maxsum,currmaxsum);
            
//         totalsum+=arr[i];
//     }
//     int cirsum = totalsum - minsum;
        
//     if(totalsum==minsum)
//         cout<<"Max circular subarray sum is: "<<maxsum<<endl;
//     else
//         cout<<"Max circular subarray sum is: "<<max(maxsum,cirsum)<<endl;
//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int circularSubarraySum(vector<int>& arr) {
//     int n = arr.size();
//     int res = arr[0];

//     for (int i = 0; i < n; i++) {
//         int currSum = 0;

//         // Subarray of length up to n, wrapping around
//         for (int j = 0; j < n; j++) {
//             int idx = (i + j) % n; // circular index
//             currSum += arr[idx];
//             res = max(res, currSum);
//         }
//     }
//     return res;
// }

// int main() {
//     vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
//     cout << "Maximum Circular Subarray Sum: " << circularSubarraySum(arr) << endl;
//     return 0;
// }