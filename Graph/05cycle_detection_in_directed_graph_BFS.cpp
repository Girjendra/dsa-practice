#include <bits/stdc++.h>
using namespace std;
// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, vector<int>> adj;
  for(int i = 0; i < edges.size(); i++)
    adj[edges[i].first].push_back(edges[i].second);
    
  vector<int> indegree(n+1);
  for(auto i : adj) {
      for(auto j : i.second)
        indegree[j]++;
  }

  queue<int> que;
  for(int i = 1; i <= n; i++) {
      if(indegree[i] == 0)
        que.push(i);
  }

  int ans = 0;
    while(!que.empty()) {
        int front = que.front();
        que.pop();

        ans++;

        for(auto neighbour : adj[front]) {
            indegree[neighbour]--;

            if(indegree[neighbour] == 0)
                que.push(neighbour);
        }
    }
    return !(ans == n);
}