#include <bits/stdc++.h>
using namespace std;
// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
bool isDFScycle(int node, unordered_map<int, bool>& visited,
    unordered_map<int, bool>& DFSvisited, unordered_map<int, vector<int>>& adj) {
  visited[node] = true;
  DFSvisited[node] = true;

    for(auto neighbor : adj[node]) {
      if(!visited[neighbor]) {
          int ans = isDFScycle(neighbor, visited, DFSvisited, adj);
          if(ans)
            return true;
      }
      else if(DFSvisited[neighbor]) {
          return true;
      }
  }
  DFSvisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, vector<int>> adj;
  for(int i = 0; i < edges.size(); i++)
    adj[edges[i].first].push_back(edges[i].second);
    
  unordered_map<int, bool> visited, DFSvisited;
  for(int i = 1; i <= n; i++) {
    visited[i] = false;
    DFSvisited[i] = false;
  }

  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      int ans = isDFScycle(i, visited, DFSvisited, adj);
      if(ans)
        return 1;
    }
  }
  return 0;
}