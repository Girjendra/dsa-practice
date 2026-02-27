#include <bits/stdc++.h>
using namespace std;
// TC = SC = O(n)
int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
// TC = O(n)
// SC = O(1)
int main() {
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++) {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    cout << prev1 << endl;
    return 0;
}