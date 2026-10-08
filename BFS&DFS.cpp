#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS
void BFS(int start, vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// DFS
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {

    // Graph
    vector<vector<int>> adj = {
        {1, 2},    // 0
        {0, 3},    // 1
        {0, 4},    // 2
        {1},       // 3
        {2}        // 4
    };

    cout << "BFS: ";
    BFS(0, adj);

    vector<bool> visited(5, false);

    cout << "\nDFS: ";
    DFS(0, adj, visited);

    return 0;
}
