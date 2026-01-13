#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<long long> size;
    long long current_total_ans;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 0);
        current_total_ans = 0;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    long long calc(long long len) {
        return len * (len + 1) / 2;
    }

    void activate(int i) {
        size[i] = 1;
        current_total_ans += 1;
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            current_total_ans -= calc(size[root_i]);
            current_total_ans -= calc(size[root_j]);
            
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
            
            current_total_ans += calc(size[root_j]);
        }
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    if (n < 2) {
        return; 
    }

    vector<vector<int>> positions(n); 
    for (int i = 0; i < n - 1; ++i) {
        int diff = abs(p[i] - p[i+1]);
        if (diff < n) {
            positions[diff].push_back(i + 1); 
        }
    }

    DSU dsu(n); 
    vector<long long> ans(n);
    vector<bool> active(n, false);

    for (int k = n - 1; k >= 1; --k) {
        for (int idx : positions[k]) {
            active[idx] = true;
            dsu.activate(idx);

            if (idx > 1 && active[idx - 1]) {
                dsu.unite(idx - 1, idx);
            }
            if (idx < n - 1 && active[idx + 1]) {
                dsu.unite(idx, idx + 1);
            }
        }
        ans[k] = dsu.current_total_ans;
    }

    for (int k = 1; k < n; ++k) {
        cout << ans[k] << (k == n - 1 ? "" : " ");
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