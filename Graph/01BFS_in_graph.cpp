#include <bits/stdc++.h>
using namespace std;

// TC = O(V + E)
// SC = O(V)
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    queue<int> que;
    unordered_map<int, bool> Map;

    que.push(adj[0][0]);
    for(int i = 0; i < n; i++)
        Map[i] = false;
    
    Map[adj[0][0]] = true;

    vector<int> ans;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        ans.push_back(cur);

        int size = adj[cur].size();
        for(int j = 1; j < size; j++) {
            if(Map[adj[cur][j]] == false) {
                Map[adj[cur][j]] = true;
                que.push(adj[cur][j]);
            }
        }
    }
    return ans;
}