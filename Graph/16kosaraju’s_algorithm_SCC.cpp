#include<bits/stdc++.h>
using namespace std;
// TC = O(V + E)
// SC = O(V + E) + O(V) + O(V)
void DFS(int node, vector<bool>& visited, stack<int>& st, unordered_map<int, vector<int>>& adj) {
	visited[node] = true;

	for(auto nbr : adj[node]) {
		if(!visited[nbr]) {
			DFS(nbr, visited, st, adj);
		}
	}
	st.push(node);
}

void newdfs(int node, vector<bool>& newvis, unordered_map<int, vector<int>>& adj) {
	newvis[node] = true;

	for(auto nbr : adj[node]) {
		if(!newvis[nbr])
			newdfs(nbr, newvis, adj);
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
	unordered_map<int, vector<int>> adj;
	for(int i = 0; i < edges.size(); i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
	}

	stack<int> st;
	vector<bool> visited(v);
	for(int i = 0; i < v; i++)
		visited[i]  = false;
	
	for(int i = 0; i < v; i++) {
		if(!visited[i]) {
			DFS(i, visited, st, adj);
		}
	}

	unordered_map<int, vector<int>> transpose;

	for(int i = 0; i < edges.size(); i++) {
		transpose[edges[i][1]].push_back(edges[i][0]);
	}

	vector<bool> newvis(v, false);
	int count = 0;
	while(!st.empty()) {
		int top = st.top();
		st.pop();

		if(!newvis[top]) {
			count++;
			newdfs(top, newvis, transpose);
		}
	}
	
	return count;
}