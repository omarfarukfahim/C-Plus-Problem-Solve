#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int next_i) {
        int root_i = find(i);
        int root_next = find(next_i);
        if (root_i != root_next) {
            parent[root_i] = root_next;
        }
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> p;
    p.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            p.push_back(i + 1);
        }
    }

    int num_ops = n / 2;
    vector<int> ans(num_ops + 1, 0);
    vector<bool> gap_used(num_ops + 1, false);

    DSU dsu(p.size());
    vector<bool> used_flag(p.size(), false);

    for (int i = (int)p.size() - 1; i >= 0; --i) {
        if (used_flag[i]) continue;

        int u = p[i];
        int min_val = u - num_ops;
        
        auto it = lower_bound(p.begin(), p.end(), min_val);
        int j_start = distance(p.begin(), it);

        int j = dsu.find(j_start);
        int checks = 0;

        while (j < i && checks < 200) {
            int v = p[j];
            int gap = u - v;

            if (gap > 0 && gap <= num_ops && !gap_used[gap]) {
                ans[gap] = v;
                gap_used[gap] = true;
                
                used_flag[i] = true;
                used_flag[j] = true;
                
                dsu.unite(j, j + 1);
                dsu.unite(i, i + 1);
                break;
            }

            int next_j = dsu.find(j + 1);
            if (next_j == j) j++; 
            else j = next_j;
            
            checks++;
        }
    }

    for (int x = 1; x <= num_ops; ++x) {
        cout << ans[x] << (x == num_ops ? "" : " ");
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