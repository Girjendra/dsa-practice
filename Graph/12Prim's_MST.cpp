#include <bits/stdc++.h> 
using namespace std;
// TC = O(n^2)
// SC = O(n)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[1] = 0;

    for(int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u;

        for(int j = 1; j <= n; j++) {
            if(mini > key[j] && mst[j] == false) {
                u = j;
                mini = key[j];
            }
        }

        mst[u] = true;

        for(auto neighbour : adj[u]) {
            int v = neighbour.first;
            int w = neighbour.second;

            if(mst[v] == false && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;

    for(int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i},key[i]});
    }
    return ans;
}