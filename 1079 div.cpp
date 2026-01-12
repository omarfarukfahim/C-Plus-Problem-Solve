#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
bool dp[200005][3];

void dfs(int u, int p) {
    bool is_leaf = true;
    
    // Base state for summation: {0 shakes} is achievable (remainder 0)
    bool current[3] = {true, false, false};
    
    for (int v : adj[u]) {
        if (v == p) continue;
        is_leaf = false;
        
        dfs(v, u);
        
        bool next_state[3] = {false, false, false};
        for (int r1 = 0; r1 < 3; ++r1) {
            if (current[r1]) {
                for (int r2 = 0; r2 < 3; ++r2) {
                    if (dp[v][r2]) {
                        next_state[(r1 + r2) % 3] = true;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i) current[i] = next_state[i];
    }

    if (is_leaf) {
        // Leaves must be shaken themselves (1 shake)
        dp[u][0] = false;
        dp[u][1] = true;
        dp[u][2] = false;
    } else {
        // Option 1: Don't shake u (take sum of children)
        for (int i = 0; i < 3; ++i) dp[u][i] = current[i];
        
        // Option 2: Shake u (counts as 1 shake, covers all descendants)
        dp[u][1] = true; 
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    adj.assign(n + 1, vector<int>());
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    if (dp[1][0]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}