#include <bits/stdc++.h>
using namespace std;
// TC = ON(sqrt(n)^n) or O(2^n)
// SC = O(n) (recursion stack)
int solve(int n) {
    if (n == 0)
        return 0;

    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        int temp = 1 + solve(n - i * i);
        ans = min(ans, temp);
    }
    return ans;
}
int minSquares(int n) {
    return solve(n);
}




#include <bits/stdc++.h>
using namespace std;
// TC = O(n*sqrt(n))
// SC = O(n) (dp array + recursion stack)
int solve(int n, vector<int> &dp) {
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        int temp = 1 + solve(n - i * i, dp);
        ans = min(ans, temp);
    }

    dp[n] = ans;
    return ans;
}
int minSquares(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}



#include <bits/stdc++.h>
using namespace std;
// TC = O(n*sqrt(n))
// SC = O(n) (dp array)
int solve(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++){
        int ans = i;
        for (int j = 1; j * j <= n; j++) {
            if (i - j * j >= 0 && dp[i - j * j] != INT_MAX)
                ans = min(ans, 1 + dp[i - j * j]);
        }
        dp[i] = ans;
    }
    return dp[n];
}
int minSquares(int n){
    return solve(n);
}