#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Speed up C++ I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n;
    cin >> n;

    // Adjacency list to store the tree
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    // Reading edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // BFS to calculate the number of nodes at each depth
    vector<int> level_counts(n + 1, 0);
    vector<int> dist(n + 1, -1);
    queue<int> q;

    // Start BFS from Root (Index 1)
    dist[1] = 0;
    level_counts[0] = 1;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { // If unvisited
                dist[v] = dist[u] + 1;
                level_counts[dist[v]]++;
                q.push(v);
            }
        }
    }

    int ans = 0;

    // 1. Check Constraint A: Max nodes at any single depth
    for (int count : level_counts) {
        ans = max(ans, count);
    }

    // 2. Check Constraint B: Max Clique formed by a node and its children
    // For Root: Clique = Root + All Children = degree[1] + 1
    ans = max(ans, degree[1] + 1);

    // For other nodes: Clique = Node + Children. 
    // Since degree includes the parent, Children = degree - 1.
    // Clique size = 1 + (degree - 1) = degree.
    for (int i = 2; i <= n; ++i) {
        ans = max(ans, degree[i]);
    }

    cout << ans << "\n";
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}