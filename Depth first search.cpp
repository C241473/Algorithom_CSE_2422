#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
void DFS(int node, vector<vector<int>>& adj) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj);
        }
    }
}

int main() {
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);
    visited.assign(n, false);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout << "Enter start node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start, adj);

    cout << endl;
    return 0;
}
