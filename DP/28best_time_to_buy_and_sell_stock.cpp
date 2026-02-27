#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int minprice = prices[0];
    int pro = 0;
    for(int i=1;i<prices.size();i++){
            int d = prices[i]-minprice;
            pro = max(pro,d);
            minprice = min(prices[i], minprice);
    }
    return pro;
}




int solve(vector<int>& prices, int i, int minPrice, int maxProfit) {
    if(i == prices.size())
        return maxProfit;

    maxProfit = max(maxProfit, prices[i] - minPrice);
    minPrice = min(minPrice, prices[i]);

    return solve(prices, i + 1, minPrice, maxProfit);
}
int maxProfit(vector<int>& prices) {
    return solve(prices, 1, prices[0], 0);
}