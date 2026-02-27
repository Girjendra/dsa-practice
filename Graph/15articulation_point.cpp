// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  // TC: O(N + E)
  // SC: O(N + E) + O(N) + O(N)
  void DFS(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, 
    vector<int> adj[], vector<int>& ap, unordered_map<int, bool>& visited) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;
        
        for(auto nbr : adj[node]) {
            if(!visited[nbr]) {
                DFS(nbr, node, timer, disc, low, adj, ap, visited);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr] >= disc[node] && parent != -1) 
                    ap.push_back(node);
                child++;
            }
            else if(nbr != parent) {
                low[node] = min(low[node], disc[nbr]);
            }
        }
         
        if(parent == -1 && child > 1)
            ap.push_back(node);
    }
  
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        int timer = 0;
        vector<int> disc(V);
        vector<int> low(V);
        unordered_map<int, bool> visited;
    
        for(int i = 0; i < V; i++) {
            disc[i] = -1;
            low[i] = -1;
        }
    
        vector<int> ap;
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DFS(i, -1, timer, disc, low, adj, ap, visited);
            }
        }
        
        if(ap.empty()) 
            return {-1};
            
        sort(ap.begin(), ap.end());
        // ap.erase(unique(ap.begin(), ap.end()), ap.end());
        set<int> st(ap.begin(), ap.end());
        vector<int> ans;
        for(int it : st)
            ans.push_back(it);
        return ans;
    }  
};