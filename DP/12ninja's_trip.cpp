#include<bits/stdc++.h>
using namespace std;
// TC = O(3^n)
// SC = O(n) for recursive stack space
int solve(int n, vector<int>& days, vector<int>& cost, int i) {
    if(i >= n)
        return 0;
    
    int n1 = cost[0] + solve(n, days, cost, i+1);

    int index;

    for(index = i; index < n && days[index] < days[i] + 7; index++);
    int n2 = cost[1] + solve(n, days, cost, index);

    for(index = i; index < n && days[index] < days[i] + 30; index++);
    int n3 = cost[2] + solve(n, days, cost, index);

    return min(n1, min(n2, n3));
}
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    return solve(n, days, cost, 0);
}



// TC = O(n)
// SC = O(n) for dp array + O(n) for recursive stack space
int solve(int n, vector<int>& days, vector<int>& cost, int i, vector<int>& dp) {
    if(i >= n)
        return 0;
    if(dp[i] != -1)
        return  dp[i];

    int n1 = cost[0] + solve(n, days, cost, i+1, dp);

    int index;

    for(index = i; index < n && days[index] < days[i] + 7; index++);
    int n2 = cost[1] + solve(n, days, cost, index, dp);

    for(index = i; index < n && days[index] < days[i] + 30; index++);
    int n3 = cost[2] + solve(n, days, cost, index, dp);

    int ans = min(n1, min(n2, n3));
    dp[i] = ans;
    return ans;
}
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    vector<int> dp(n+1, -1);
    return solve(n, days, cost, 0, dp);
}



// TC = O(n)
// SC = O(n) for dp array
int solve(int n, vector<int>& days, vector<int>& cost) {
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for(int k =  n-1; k >= 0; k--) {
        int n1 = cost[0] + dp[k+1];
        int index;
        for(index = k; index < n && days[index] < days[k] + 7; index++);
        int n2 = cost[1] + dp[index];

        for(index = k; index < n && days[index] < days[k] + 30; index++);
        int n3 = cost[2] + dp[index];

        int ans = min(n1, min(n2, n3));
        dp[k] = ans;
    }
    return dp[0];
}
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    return solve(n, days, cost);
}



// TC = O(n)
// SC = O(1)
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for(int day : days) {

        while(!month.empty() && month.front().first + 30 <= day)
            month.pop();

        while(!week.empty() && week.front().first + 7 <= day)
            week.pop();

        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));
        
        ans = min(ans+cost[0], min(month.front().second, week.front().second));
    }
    return ans;
}