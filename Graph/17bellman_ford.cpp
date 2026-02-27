#include <bits/stdc++.h>
using namespace std;
// TC = O(V * E)
// SC = O(V)
int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
    vector<int> dist(n, pow(10, 8));

    dist[0] = 0;
    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative-weight cycles in one more iteration, if we get a shorter path, then there is a negative weight cycle
    for (int j = 0; j < edges.size(); j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] + w < dist[v])
            return 1;
    }
    return 0;
}