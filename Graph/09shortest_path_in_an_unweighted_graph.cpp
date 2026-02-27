#include <bits/stdc++.h>
using namespace std; 
// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t) {
	unordered_map<int, vector<int>> adj;
    for(int i = 0; i < m; i++) {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

	unordered_map<int, bool> visited;
    for(int i = 1; i <= n; i++)
        visited[i] = false;
    
    vector<int> parent(n+1,0);

    queue<int> que;
    que.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!que.empty()) {
        int front = que.front();
        que.pop();

        for(auto neighbour : adj[front]) {
            if(!visited[neighbour]) {
                parent[neighbour] = front;
                visited[neighbour] = true;
                que.push(neighbour);
            }
        }
    }
	
    vector<int> ans;
    ans.push_back(t);
    int par = parent[t];

    while(par != -1) {
        ans.push_back(par);
        par = parent[par];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}