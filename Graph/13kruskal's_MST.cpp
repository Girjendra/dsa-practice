#include<bits/stdc++.h>
using namespace std; 
// TC = O(E log E) + O(E * α(V))
// SC = O(V) + O(V)
bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int findparent(int node, vector<int>& parent) {
    if(parent[node] == node)
        return node;
    
    parent[node] = findparent(parent[node], parent);
    return parent[node];
}

void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findparent(u, parent);
    v = findparent(v, parent);

    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int total = 0;
    int size = edges.size();
    for(int i = 0; i < size; i++) {
        int u = findparent(edges[i][0], parent);
        int v = findparent(edges[i][1], parent);
        int wt = edges[i][2];

        // cycle not formed
        if(u != v) {
            total += wt;
            unionset(u, v, parent, rank);
        }
    }
    return total;
}