#include <bits/stdc++.h>
using namespace std; 

// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
void DFS(int node, unordered_map<int, int>& visited, unordered_map<int, vector<int>>& adj, stack<int>& st) {
    visited[node] = true;

    for(auto neighbor : adj[node]) {
        if(!visited[neighbor])
            DFS(neighbor, visited, adj, st);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < e; i++)
        adj[edges[i][0]].push_back(edges[i][1]);

    unordered_map<int, int> visited;
    for(int i = 0; i < v; i++)
        visited[i] = false;
    
    stack<int> st;
    for(int i = 0;i < v; i++) {
        if(!visited[i]) {
            DFS(i, visited, adj, st);
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        ans.push_back(top);
    }
    return ans;
}