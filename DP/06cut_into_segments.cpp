#include<bits/stdc++.h>
using namespace std;
// TC -> O(3^n)
// SC -> O(n) recursion stack
int solve(int n, int x, int y, int z) {
	if(n == 0)
		return 0;

	if(n < 0)
		return INT_MIN;
	
	int n1 = solve(n-x, x, y, z);
	int n2 = solve(n-y, x, y, z);
	int n3 = solve(n-z, x, y, z);

	return 1 + max(n1, max(n2, n3));
}
int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n, x, y, z);
	if(ans < 0)
		return 0;
	else
		return ans;
}




// TC -> O(n)
// SC -> O(n) + O(n) for dp array
int solve(int n, int x, int y, int z, vector<int>& dp) {
	if(n == 0)
		return 0;

	if(n < 0)
		return INT_MIN;
	
	if(dp[n] != INT_MIN)
		return dp[n];

	int n1 = solve(n-x, x, y, z, dp);
	int n2 = solve(n-y, x, y, z, dp);
	int n3 = solve(n-z, x, y, z, dp);

	int ans = 1 + max(n1, max(n2, n3));
	dp[n] = ans;
	return ans;
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, INT_MIN);
	int ans = solve(n, x, y, z, dp);
	if(ans < 0)
		return 0;
	else
		return ans;
}




// TC -> O(n)
// SC -> O(n) for dp array
int solve(int n, int x, int y, int z) {
	vector<int> dp(n+1, INT_MIN);	
	dp[0] = 0;

	int ans = INT_MIN;
	for(int i = 1; i <= n; i++) {		
		if(i-x >= 0)
			dp[i] = max(dp[i], dp[i-x] + 1);
		if(i-y >= 0)
			dp[i] = max(dp[i], dp[i-y] + 1);
		if(i-z >= 0)
			dp[i] = max(dp[i], dp[i-z] + 1);
	}

	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n, x, y, z);
	if(ans < 0)
		return 0;
	else
		return ans;
}