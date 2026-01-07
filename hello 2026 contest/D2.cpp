#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MAXN = 200005;
vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN];
int color[MAXN];
vector<int> nodes_at_depth[MAXN];
int seen_bad[MAXN]; 
int seen_timer = 0;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        nodes_at_depth[i].clear();
        degree[i] = 0; 
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    depth[1] = 0;
    parent[1] = 0;
    nodes_at_depth[0].push_back(1);
    
    vector<int> children_count(n + 1, 0);

    int max_depth = 0;
    
    for(int i=0; i<=n; i++) parent[i] = -1; 
    parent[1] = 0; 
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        max_depth = max(max_depth, depth[u]);
        
        for(int v : adj[u]){
            if(v != parent[u]){
                parent[v] = u;
                depth[v] = depth[u] + 1;
                nodes_at_depth[depth[v]].push_back(v);
                children_count[u]++;
                q.push(v);
            }
        }
    }

    int k = 0;
    
    for(int d = 0; d <= max_depth; ++d) {
        k = max(k, (int)nodes_at_depth[d].size());
    }
    
    for(int i = 1; i <= n; ++i) {
        k = max(k, children_count[i] + 1);
    }

    color[1] = 1;

    for (int d = 1; d <= max_depth; ++d) {
        const vector<int>& nodes = nodes_at_depth[d];
        int m = nodes.size();
        
        
        seen_timer++; 
        
        for (int i = 0; i < m; ++i) {
            int u = nodes[i];
            int p = parent[u];
            int p_color = color[p]; 
            
            
            int bad_s = (p_color - 1 - i) % k;
            if (bad_s < 0) bad_s += k;
            
            seen_bad[bad_s] = seen_timer;
        }
        
        int best_S = -1;
        for (int s = 0; s < k; ++s) { 
            if (seen_bad[s] != seen_timer) {
                best_S = s;
                break;
            }
        }
        
        for (int i = 0; i < m; ++i) {
            color[nodes[i]] = ((i + best_S) % k) + 1;
        }
    }

    cout << k << "\n";
    vector<vector<int>> ops(k + 1);
    for (int i = 1; i <= n; ++i) {
        ops[color[i]].push_back(i);
    }
    
    for (int i = 1; i <= k; ++i) {
        cout << ops[i].size();
        for (int u : ops[i]) {
            cout << " " << u;
        }
        cout << "\n";
    }
}

int main() {
    fast_io();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}