#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Segment Tree to efficiently find the first index in a range [L, R]
// with a value strictly greater than a threshold val.
struct SegTree {
    int n;
    vector<int> tree; // Stores the maximum value in the range

    SegTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    void build(const vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(a, 2 * node, start, mid);
            build(a, 2 * node + 1, mid + 1, end);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Returns the smallest index i in [l, r] such that a[i] > val
    // Returns -1 if no such index exists.
    int query(int node, int start, int end, int l, int r, int val) {
        // Range completely outside or max value in range is too small
        if (r < start || end < l || tree[node] <= val) {
            return -1;
        }
        // Leaf node
        if (start == end) {
            return start;
        }
        int mid = (start + end) / 2;
        // Try left child first to get the smallest index
        int res = query(2 * node, start, mid, l, r, val);
        if (res != -1) {
            return res;
        }
        // Otherwise try right child
        return query(2 * node + 1, mid + 1, end, l, r, val);
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> p(n);
    // 0-based index for implementation, but values are 1-based
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    // Step 1: Identify indices of running minima
    vector<int> s;
    int current_min = n + 1;
    for (int i = 0; i < n; ++i) {
        if (p[i] < current_min) {
            s.push_back(i);
            current_min = p[i];
        }
    }

    // Step 2: Prepare Segment Tree for finding bridges
    SegTree st(p);
    vector<pair<int, int>> edges;

    // Step 3: Process groups
    // A group G_i goes from s[i] to s[i+1]-1 (or n-1 for the last one)
    for (size_t i = 0; i < s.size(); ++i) {
        int start = s[i];
        int end = (i + 1 < s.size()) ? s[i+1] : n;

        // Intra-group connections: connect all nodes in (start, end) to s[i]
        for (int j = start + 1; j < end; ++j) {
            // p[j] is guaranteed > p[s[i]] because s[i+1] is the next minimum
            edges.push_back({p[start], p[j]});
        }

        // Inter-group connection: connect s[i] to something to the right
        // We need this for all groups except the last one (which contains value 1)
        if (i < s.size() - 1) {
            // Find smallest index idx >= s[i+1] such that p[idx] > p[s[i]]
            int target_idx = st.query(1, 0, n - 1, s[i+1], n - 1, p[s[i]]);
            
            if (target_idx == -1) {
                cout << "No\n";
                return;
            }
            edges.push_back({p[s[i]], p[target_idx]});
        }
    }

    cout << "Yes\n";
    for (auto& edge : edges) {
        cout << edge.first << " " << edge.second << "\n";
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