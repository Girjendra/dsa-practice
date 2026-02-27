#include<bits/stdc++.h>
using namespace std;
// TC = O(n1*n2)
// SC = O(n2)
int solve(string& a, string& b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> cur(n2+1, 0);
    vector<int> next(n2+1, 0);
    
    for(int i = n1-1; i >= 0; i--) {
        for(int j = n2-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + next[j+1];
            else
                ans = max(next[j], cur[j+1]);
            
            cur[j] = ans;
        }
        next = cur;
    }
    return next[0];
}
int longestPalindromeSubseq(string s) {
    string b = s;
    reverse(s.begin(), s.end());
    return solve(s, b);
}