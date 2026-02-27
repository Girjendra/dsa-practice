/*
Problem statement
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges,
the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0]
and GRAPH[i][1]. print its DFS traversal.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
*/

#include <bits/stdc++.h>
using namespace std;

// TC = O(V + E)
// SC = O(V)
vector<vector<int>> dfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int, bool> visited;
    for(int i = 0; i < adj.size(); i++)
        visited[i] = false;

    vector<vector<int>> ans;
    stack<int> st;

    st.push(adj[0][0]);
    visited[adj[0][0]] = true;

    vector<int> temp;

    while(!st.empty()) {
        int cur = st.top();
        st.pop();

        temp.push_back(cur);
        int size = adj[cur].size();
        for(int i = 0; i < size; i++) {
            if(visited[adj[cur][i]] == false) {
                visited[adj[cur][i]] = true;
                st.push(adj[cur][i]);
            }
        }

        if(st.empty()) {
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            temp.clear();

            for(auto node : visited) {
                if(node.second == false) {
                    st.push(node.first);
                    visited[node.first] = true;
                    break;
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}




// TC = O(V + E)
// SC = O(V)

void dfs(int node, 
         unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj,
         vector<int> &component) 
{
    // add current node to component
    component.push_back(node);
    visited[node] = true;

    // recursive call for all connected nodes
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {

    // prepare adjacency list
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);   // because graph is undirected
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // for all nodes call DFS
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}
