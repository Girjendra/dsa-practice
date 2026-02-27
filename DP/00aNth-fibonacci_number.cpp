#include <bits/stdc++.h>
using namespace std;
// TC = O(n)
// SC = O(n) + O(n) (recursion stack space)
int fiboo(int n, vector<int> &dp) {
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] == -1)
        dp[n] = fiboo(n - 1, dp) + fiboo(n - 2, dp);
    else
        return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fiboo(n, dp) << endl;
    return 0;
}