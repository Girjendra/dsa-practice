#include <bits/stdc++.h>
using namespace std;

// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
bool iscycleDFS(int node, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;

    for(auto nieghbor : adj[node]) {
        if(!visited[nieghbor]) {
            bool ans = iscycleDFS(nieghbor, node, visited, adj);
            if(ans)
                return true;
        }
        else if(nieghbor != parent)
            return true;
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    unordered_map<int, bool> visited;
    for(int i = 1; i <= n; i++)
        visited[i] = false;

    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {
            bool ans = iscycleDFS(i, -1, visited, adj);
            if(ans == true)
                return "Yes";
        }
    }

    return "No";
}