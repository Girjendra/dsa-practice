#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> a, vector<int> b) {
    if(a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2])
        return true;
    else
        return false;
}
int solve(vector<vector<int>>& a, int n) {
    vector<int> current(n+1, 0);
    vector<int> next(n+1, 0);
    
    for(int cur = n-1; cur >= 0; cur--) {
        for(int prev = cur-1; prev >= -1; prev--) {
            int in = 0;
            if(prev == -1 || check(a[cur], a[prev])) {
                in = a[cur][2] + next[cur+1];
            }
            
            int ex = 0 + next[prev+1];
            
            current[prev+1] = max(in, ex);
        }
        next = current;
    }
    return next[0];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto& cub : cuboids) {
        sort(cub.begin(), cub.end());
    }

    sort(cuboids.begin(), cuboids.end());
    int n = cuboids.size();
    return solve(cuboids, n);
}
