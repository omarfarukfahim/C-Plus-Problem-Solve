#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 5005;

int n;
string s;
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN];
int dfs_order[MAXN];
int timer;

int dp[MAXN][MAXN]; 
int W[MAXN][MAXN]; 
int Z[MAXN][MAXN];

long long pref[MAXN][MAXN];

void dfs(int u) {
    timer++;
    tin[u] = timer;
    dfs_order[timer] = u;
    
    for (int v : adj[u]) {
        dfs(v);
    }
    
    tout[u] = timer;
}

void solve() {
    if (!(cin >> n)) return;
    cin >> s;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    timer = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> children(n + 1);
    vector<int> q;
    q.push_back(1);
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    
    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        for(int v : adj[u]){
            if(v != parent[u]){
                visited[v] = true;
                parent[v] = u;
                children[u].push_back(v);
                q.push_back(v);
            }
        }
    }
    
    for(int i=1; i<=n; ++i) adj[i] = children[i];

    dfs(1);

    for (int i = n; i >= 1; --i) {
        int u = dfs_order[i];
        
        for (int j = n; j >= 1; --j) {
            int v = dfs_order[j];
            
            long long sum_w = 0;
            for (int c : adj[v]) {
                sum_w += dp[u][c];
                sum_w += W[u][c];
            }
            W[u][v] = sum_w % MOD;
            
            long long sum_z = 0;
            for (int c : adj[u]) {
                sum_z += W[c][v];
                sum_z += Z[c][v];
            }
            Z[u][v] = sum_z % MOD;
            
            if (s[u-1] == s[v-1]) {
                dp[u][v] = (1 + Z[u][v]) % MOD;
            } else {
                dp[u][v] = 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int u = dfs_order[i];
            int v = dfs_order[j];
            
            long long val = dp[u][v];
            pref[i][j] = (val + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]) % MOD;
            if (pref[i][j] < 0) pref[i][j] += MOD;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int l = tin[i];
        int r = tout[i];
        
        long long ans = pref[r][r] - pref[l-1][r] - pref[r][l-1] + pref[l-1][l-1];
        ans %= MOD;
        if (ans < 0) ans += MOD;
        
        cout << ans << (i == n ? "" : " ");
    }
    cout << "\n";
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