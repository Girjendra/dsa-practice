/*
You are given a 2D integer array items, where items[i] = [factori, pricei] represents the ith item. You are also given an integer budget.
There are unlimited copies of each item available for purchase.You may buy any number of copies of any items such that the total cost of the
purchased copies is at most budget.
After buying items, you may receive free copies according to the following rules:
For each item i that you bought at least one copy of, you receive one free copy of every item j such that j != i and factori divides factorj.
Buying multiple copies of the same item i does not give additional free copies through item i.
The same item j can be received multiple times for free if it is received from purchases of different item types.
Return the maximum total number of item copies you can obtain, including both purchased copies and free copies, while spending at most budget on purchased items.

Example 1:
Input: items = [[6,2],[2,6],[3,4]], budget = 9
Output: 4
Explanation:
You can buy 2 copies of item 0 and 1 copy of item 2 for a total cost of 2 * 2 + 4 = 8, which is not greater than budget = 9.
Buying item 2 gives 1 free copy of item 0, because factor2 = 3 divides factor0 = 6.
You leave with 3 purchased copies and 1 free copy, for a total of 4 item copies.
Example 2:

Input: items = [[2,4],[3,2],[4,1],[6,4],[12,4]], budget = 8
Output: 10
Explanation:
You can buy 1 copy of item 0, 1 copy of item 1, and 2 copies of item 2 for a total cost of 4 + 2 + 2 * 1 = 8.
Buying item 0 gives 1 free copy of items 2, 3, and 4.
Buying item 1 gives 1 free copy of items 3 and 4.
Buying item 2 gives 1 free copy of item 4.
Thus, you receive 6 free copies. You leave with 4 purchased copies and 6 free copies, for a total of 10 item copies.

Constraints:
1 <= items.length <= 1000
items[i] = [factori, pricei]
1 <= factori, pricei <= 1500
1 <= budget <= 1500
*/
#include<iostream>
#include <vector>
using namespace std;









// TC : O(n^2 * 2^(n + b)) SC : O(n + b)
class Solution {
public:
    int solve(int i, int budget, bool used, vector<vector<int>>& items, vector<int>& bonus) {
        int n = items.size();
        if(i == n)
            return 0;

        int skip = solve(i + 1, budget, false, items, bonus);
        int take = 0;
        int price = items[i][1];

        if(budget >= price) {
            int gain = 1;

            if(!used)
                gain += bonus[i];

            take = gain + solve(i, budget - price, true, items, bonus);
        }

        return max(skip, take);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0)
                    bonus[i]++;
            }
        }

        return solve(0, budget, false, items, bonus);
    }
};










// TC : O(n^2 + n * b ) SC : O(n * b + n + b)
class Solution {
public:
    vector<int> bonus;
    vector<vector<vector<int>>> dp;
    int solve(int i, int budget, int used, vector<vector<int>>& items) {
        int n = items.size();
        if(i == n)
            return 0;

        int &res = dp[i][budget][used];
        if(res != -1)
            return res;

        res = solve(i + 1, budget, 0, items);
        int price = items[i][1];
        if(budget >= price) {
            int gain = 1;

            if(!used)
                gain += bonus[i];

            res = max(res, gain + solve(i, budget - price, 1, items));
        }

        return res;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        bonus.assign(n, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && items[j][0] % items[i][0] == 0)
                    bonus[i]++;

        dp.assign(n, vector<vector<int>>(budget + 1, vector<int>(2, -1)));
        return solve(0, budget, 0, items);
    }
};











// TC : O(n^2 + n * b ) SC : O(n + b)
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n, 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && items[j][0] % items[i][0] == 0)
                    bonus[i]++;

        vector<int> dp(budget + 1, 0);
        for(int i = 0; i < n; i++) {
            int price = items[i][1];

            for(int b = budget; b >= price; b--)
                dp[b] = max(dp[b], dp[b - price] + 1 + bonus[i]);

            for(int b = price; b <= budget; b++)
                dp[b] = max(dp[b], dp[b - price] + 1);
        }

        return dp[budget];
    }
};