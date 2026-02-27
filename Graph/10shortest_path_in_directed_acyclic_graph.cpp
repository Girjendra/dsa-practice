#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // // TC: O(N + E)
    // SC: O(N + E) + O(N) + O(N)
    void DFS(int node, unordered_map<int, int>& visited, unordered_map<int, vector<pair<int, int>>>& adj, stack<int>& st) {
        visited[node] = true;
    
        for(auto neighbour : adj[node]) {
            if(!visited[neighbour.first])
                DFS(neighbour.first, visited, adj, st);
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i= 0; i < E; i++) {
            pair<int, int> temp = make_pair(edges[i][1],edges[i][2]);
            adj[edges[i][0]].push_back(temp);
        }
        
        unordered_map<int, int> visited;
        for(int i = 0; i < V; i++)
            visited[i] = false;
        
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DFS(i, visited, adj, st);
            }
        }    
        
        vector<int> dist(V);
        for(int& it : dist)
            it = -1;
            
        dist[0] = 0;
        
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            
            if(dist[top] != -1) {
                for(auto i : adj[top]) {
                    if(dist[i.first] == -1 || dist[top] + i.second < dist[i.first]) // Relaxtion step, -1 beacause of initial distance is -1
                        dist[i.first] = dist[top] + i.second;
                }
            }
        }
        
        return dist;
    }
};
