#include <bits/stdc++.h>
using namespace std;
// // TC -> O(n^x)  // TLE
// // SC -> O(x)  (recursion stack space)
// int mini(vector<int> &num, int x) {
//     if(x == 0)
//         return 0;
//     else if(x < 0)
//         return INT_MAX;
    
//     int ans = INT_MAX;
//     for(int it : num) {
//         int temp = mini(num, x-it);
//         if (temp != INT_MAX){
//             ans = min(ans, temp+1);
//         }
//     }
//     return ans;
// }

// int minimumElements(vector<int> &num, int x){
//     int ans =  mini(num, x);
//     if(ans == INT_MAX)
//         return -1;
//     return ans;
// }



// // TC -> O(n*x)
// // SC -> O(x)  (dp array)
// int mini(vector<int> &num, int x, vector<int>& dp) {
//     if(x == 0)
//         return 0;
//     else if(x < 0)
//         return INT_MAX;
//     if(dp[x] != -1)
//         return dp[x];

//     int ans = INT_MAX;
//     for(int it : num) {
//         int temp = mini(num, x-it, dp);
//         if (temp != INT_MAX){
//             ans = min(ans, temp+1);
//         }
//     }
//     dp[x] = ans;
//     return ans;
// }

// int minimumElements(vector<int> &num, int x){
//     vector<int> dp(x+1, -1);
//     int ans =  mini(num, x, dp);
//     if(ans == INT_MAX)
//         return -1;
//     return ans;
// }





// TC -> O(n*x)
// SC -> O(x)  (dp array)
int mini(vector<int> &num, int x) {
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < num.size(); j++) {
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
        }

    }

    if(dp[x] == INT_MAX)
        return -1;
    return dp[x];
}

int minimumElements(vector<int> &num, int x){
    return mini(num, x);
}