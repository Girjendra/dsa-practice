#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
class Graph {
public:
    unordered_map<int, list<int>> adj;

    // TC: O(1)
    // SC : O(1)
    void addedge(int u, int v, bool direction) {
        adj[u].push_back(v);

        if(direction == 0)
            adj[v].push_back(u);
    }

    // TC: O(V + E)
    // SC : O(1)
    void printgraph() {
        for(auto node : adj) {
            cout << node.first << ":";
            for(int it : node.second) {
                cout << it << "->";
            }
            cout << "NULL" << endl;
        }
    }
    
};

using namespace std;
int main(){
    Graph g;
    int n;
    cout << "Enter the number of node: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >>v;
        g.addedge(u, v, 0);
    }

    g.printgraph();
    return 0;
}