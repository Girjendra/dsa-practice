#include<bits/stdc++.h>
using namespace std;
// TC = O(n) SC = O(1)
int solve(vector<int>& p, int fee) {
    int n = p.size();
    vector<int> prev(2, 0);
    vector<int> cur(2, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            int pro = 0;
            if(buy) {
                pro = max((-p[i]) + prev[0], prev[1]);
            }
            else {
                pro = max((p[i]) + prev[1]- fee, prev[0]);
            }
            cur[buy] = pro;
        }
        prev = cur;
    }
    return prev[1];
}
int maxProfit(vector<int>& prices, int fee) {
    return solve(prices, fee);
}