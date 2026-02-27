#include <bits/stdc++.h>
using namespace std;
// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
bool iscycleBFS(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    queue<int> que;
    unordered_map<int, int> parent;

    parent[node] = -1;
    que.push(node);
    visited[node] = true;

    while(!que.empty()) {
        int front = que.front();
        que.pop();

        for(auto adjacent : adj[front]) {
            if(visited[adjacent] == true && adjacent != parent[front])
                return true;
            else if(!visited[adjacent]){
                que.push(adjacent);
                visited[adjacent] = true;
                parent[adjacent] = front;
            }
        }
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
            bool ans = iscycleBFS(i, visited, adj);
            if(ans == true)
                return "Yes";
        }
    }

    return "No";
}