#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 200005;
const int LOGN = 19; // 2^18 > 200000

int st[MAXN][LOGN]; // Sparse Table for GCD
int logs[MAXN];
int n;
int p[MAXN];

// GCD function
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Precompute logs and build Sparse Table
void build_sparse_table() {
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
        logs[i] = logs[i / 2] + 1;

    for (int i = 0; i < n; i++) {
        st[i][0] = p[i];
    }

    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// O(1) Range GCD Query
int query(int L, int R) {
    int j = logs[R - L + 1];
    return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

// Disjoint Set Union (DSU) for Kruskal's
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

void solve() {
    if (!(cin >> n)) return;
    for (int i = 0; i < n; i++) cin >> p[i];

    build_sparse_table();

    vector<Edge> edges;
    // Heuristic: Each node generates ~20-40 edges. 
    // N=2e5 -> ~8e6 edges. Reserve to avoid reallocation.
    edges.reserve(n * 30); 

    for (int i = 0; i < n; ++i) {
        // 1. Scan Right
        int curr = i + 1;
        while (curr < n) {
            int current_g = query(i, curr);
            
            // Binary search for the END of the range having this GCD
            int l = curr, r = n - 1, range_end = curr;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (query(i, mid) == current_g) {
                    range_end = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            // Add edge to the first element of the range (curr)
            // Note: In some variations, connecting to range_end is useful, 
            // but for "shortest edge" logic, the transition point is key.
            // Connecting i to 'curr' covers the edge (i, curr) with weight 'current_g'.
            edges.push_back({i, curr, current_g});
            
            // Move to the start of the next distinct GCD range
            curr = range_end + 1;
        }

        // 2. Scan Left
        curr = i - 1;
        while (curr >= 0) {
            int current_g = query(curr, i);
            
            // Binary search for the START of the range having this GCD
            int l = 0, r = curr, range_start = curr;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (query(mid, i) == current_g) {
                    range_start = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            
            edges.push_back({i, curr, current_g});
            curr = range_start - 1;
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long mst_cost = 0;
    int edges_count = 0;

    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_cost += e.w;
            edges_count++;
            if (edges_count == n - 1) break;
        }
    }

    cout << mst_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}