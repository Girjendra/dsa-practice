#include<bits/stdc++.h>
using namespace std;
// TC = O(2^k), SC = O(k)
int solve(int index, int end, vector<int>& slices, int bas) {
    if(index > end || bas == 0)
        return 0;

    int in = slices[index] + solve(index+2, end, slices, bas-1);
    int ex = 0 + solve(index + 1, end, slices, bas);

    return max(in, ex);
}
int maxSizeSlices(vector<int>& slices) {
    int k = slices.size();
    int case1 = solve(0, k-2, slices, k/3);
    int case2 = solve(1, k-1, slices, k/3);

    return max(case1, case2);
}






// TC = O(2^k), SC = O(k^2)
int solve(int index, int end, vector<int>& slices, int bas, vector<vector<int>>& dp) {
    if(index > end || bas == 0)
        return 0;

    if(dp[index][bas] != -1)
        return dp[index][bas];

    int in = slices[index] + solve(index+2, end, slices, bas-1, dp);
    int ex = 0 + solve(index + 1, end, slices, bas, dp);

    dp[index][bas] = max(in, ex);
    return dp[index][bas];
}
int maxSizeSlices(vector<int>& slices) {
    int k = slices.size();
    vector<vector<int>> dp1(k+1, vector<int>(k/3+1, -1));
    vector<vector<int>> dp2(k+1, vector<int>(k/3+1, -1));
    int case1 = solve(0, k-2, slices, k/3, dp1);
    int case2 = solve(1, k-1, slices, k/3, dp2);

    return max(case1, case2);
}





// TC = O(k^2), SC = O(k^2)
int solve(vector<int>& slices) {
    int k = slices.size();
    vector<vector<int>> dp1(k+2, vector<int>(k/3+1, 0));
    vector<vector<int>> dp2(k+2, vector<int>(k/3+1, 0));

    for(int index = k - 2; index >= 0; index--) {
        for(int bas = 1; bas <= k/3; bas++) {
            int in = slices[index] + dp1[index+2][bas-1];
            int ex = 0 + dp1[index + 1][bas];
            dp1[index][bas] = max(in, ex);     
        }
    }
    
    for(int index = k - 1; index > 0; index--) {
        for(int bas = 1; bas <= k/3; bas++) {
            int in = slices[index] + dp2[index+2][bas-1];
            int ex = 0 + dp2[index + 1][bas];
            dp2[index][bas] = max(in, ex);     
        }
    }
    return max(dp1[0][k/3], dp2[1][k/3]);
}
int maxSizeSlices(vector<int>& slices) {
    return solve(slices);
}




// TC = O(k^2), SC = O(k)
int solve(vector<int>& slices) {
    int k = slices.size();
    vector<int> p1(k+2, 0);
    vector<int> c1(k+2, 0);
    vector<int> n1(k+2, 0);

    vector<int> p2(k+2, 0);
    vector<int> c2(k+2, 0);
    vector<int> n2(k+2, 0);

    for(int index = k - 2; index >= 0; index--) {
        for(int bas = 1; bas <= k/3; bas++) {
            int in = slices[index] + n1[bas-1];
            int ex = 0 + c1[bas];
            p1[bas] = max(in, ex);     
        }
        n1 = c1;
        c1 = p1;
    }

    for(int index = k - 1; index > 0; index--) {
        for(int bas = 1; bas <= k/3; bas++) {
            int in = slices[index] + n2[bas-1];
            int ex = 0 + c2[bas];
            p2[bas] = max(in, ex);     
        }
        n2 = c2;
        c2 = p2;
    }

    return max(c1[k/3], c2[k/3]);
}
int maxSizeSlices(vector<int>& slices) {
    return solve(slices);
}