#include <bits/stdc++.h>
using namespace std; 
// TC: O(N + E)
// SC: O(N + E) + O(N) + O(N)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < e; i++)
        adj[edges[i][0]].push_back(edges[i][1]);
    
    vector<int> indegree(v);
    for(auto i : adj) {
        for(auto j : i.second)
            indegree[j]++;
    }

    queue<int> que;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0)
            que.push(i);
    }

    vector<int> ans;
    while(!que.empty()) {
        int front = que.front();
        que.pop();

        ans.push_back(front);

        for(auto neighbour : adj[front]) {
            indegree[neighbour]--;

            if(indegree[neighbour] == 0)
                que.push(neighbour);
        }
    }
    return ans;
}