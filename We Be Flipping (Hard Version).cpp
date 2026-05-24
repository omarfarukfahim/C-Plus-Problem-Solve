#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

namespace byteforge_omar {

    struct Node {
        bool has_0;
        bool has_1;
        bool lazy;
    };

    vector<Node> tree;

    void apply(int node) {
        swap(tree[node].has_0, tree[node].has_1);
        tree[node].lazy ^= 1;
    }

    void push(int node) {
        if (tree[node].lazy) {
            apply(2 * node);
            apply(2 * node + 1);
            tree[node].lazy = false;
        }
    }

    void build(int node, int l, int r, const vector<int>& x, const vector<bool>& in_S) {
        tree[node].lazy = false;
        if (l == r) {
            if (in_S[l]) {
                tree[node].has_0 = (x[l] == 0);
                tree[node].has_1 = (x[l] == 1);
            } else {
                tree[node].has_0 = false;
                tree[node].has_1 = false;
            }
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, x, in_S);
        build(2 * node + 1, mid + 1, r, x, in_S);
        tree[node].has_0 = tree[2 * node].has_0 | tree[2 * node + 1].has_0;
        tree[node].has_1 = tree[2 * node].has_1 | tree[2 * node + 1].has_1;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node);
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
        tree[node].has_0 = tree[2 * node].has_0 | tree[2 * node + 1].has_0;
        tree[node].has_1 = tree[2 * node].has_1 | tree[2 * node + 1].has_1;
    }

    void remove_node(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node].has_0 = false;
            tree[node].has_1 = false;
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        if (idx <= mid) remove_node(2 * node, l, mid, idx);
        else remove_node(2 * node + 1, mid + 1, r, idx);
        tree[node].has_0 = tree[2 * node].has_0 | tree[2 * node + 1].has_0;
        tree[node].has_1 = tree[2 * node].has_1 | tree[2 * node + 1].has_1;
    }

    int query_min_zero(int node, int l, int r) {
        if (!tree[node].has_0) return -1;
        if (l == r) return l;
        push(node);
        int mid = (l + r) / 2;
        if (tree[2 * node].has_0) {
            return query_min_zero(2 * node, l, mid);
        }
        return query_min_zero(2 * node + 1, mid + 1, r);
    }

    void execute_omar_logic() {
        int n;
        if (!(cin >> n)) return;

        vector<long long> a(n + 1);
        vector<int> x(n + 2, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            x[i] = (a[i] < 0 ? 1 : 0);
        }

        const long long OMAR_INF = 1e18; 
        vector<vector<long long>> dp(n + 1, vector<long long>(3, OMAR_INF));
        vector<vector<int>> choice(n + 1, vector<int>(3, 0));
        vector<vector<int>> prev_comp(n + 1, vector<int>(3, 0));

        dp[0][1] = 0; 

        for (int i = 1; i <= n; i++) {
            for (int y = 0; y <= 1; y++) {
                long long cost = y * abs(a[i]);
                for (int old_c = 0; old_c <= 2; old_c++) {
                    if (dp[i - 1][old_c] == OMAR_INF) continue;

                    int new_c;
                    if (y > x[i]) new_c = 2;
                    else if (y < x[i]) new_c = 0;
                    else new_c = old_c;

                    if (dp[i - 1][old_c] + cost < dp[i][new_c]) {
                        dp[i][new_c] = dp[i - 1][old_c] + cost;
                        choice[i][new_c] = y;
                        prev_comp[i][new_c] = old_c;
                    }
                }
            }
        }

        int curr_comp = (dp[n][1] <= dp[n][2]) ? 1 : 2;
        vector<int> y_final(n + 2, 0);

        for (int i = n; i >= 1; i--) {
            y_final[i] = choice[i][curr_comp];
            curr_comp = prev_comp[i][curr_comp];
        }

        vector<int> S;
        vector<bool> in_S(n + 1, false);
        for (int i = 1; i <= n; i++) {
            int x_xor = x[i] ^ x[i + 1];
            int y_xor = y_final[i] ^ y_final[i + 1];
            if (x_xor != y_xor) {
                S.push_back(i);
                in_S[i] = true;
            }
        }

        tree.assign(4 * n + 1, {false, false, false});
        if (n > 0) {
            build(1, 1, n, x, in_S);
        }

        vector<int> omar_ops;
        for (size_t step = 0; step < S.size(); step++) {
            int idx = query_min_zero(1, 1, n);
            if (idx == -1) break; 
            
            omar_ops.push_back(idx);
            remove_node(1, 1, n, idx);
            update(1, 1, n, 1, idx);
        }

        cout << omar_ops.size() << "\n";
        for (int i = 0; i < (int)omar_ops.size(); i++) {
            cout << omar_ops[i] << (i == (int)omar_ops.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    void execute_run() {
        int t;
        if (cin >> t) {
            while (t--) {
                execute_omar_logic();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    byteforge_omar::execute_run();

    return 0;
}