#include<bits/stdc++.h>
using namespace std;
// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
void DFS(int node, int parent, int& timer, vector<int>& disc, vector<int>& low,
    unordered_map<int, vector<int>>& adj, vector<vector<int>>& ans, unordered_map<int, bool>& visited) {
    
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto child : adj[node]) {
        if(!visited[child]) {
            DFS(child, node, timer, disc, low, adj, ans, visited);
            low[node] = min(low[node], low[child]);
            if(low[child] > disc[node]) {
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(child);
                ans.push_back(temp);
            }
        }
        else if(child != parent) {
            //back edge
            low[node] = min(low[node], disc[child]); 
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> visited;

    for(int i = 0; i < v; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> ans;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            DFS(i, parent, timer, disc, low, adj, ans, visited);
        }
    }
    return ans;
}