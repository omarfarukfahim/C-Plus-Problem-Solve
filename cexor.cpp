#include <iostream>
#include <vector>

using namespace std;

void construct(int len, int idx_offset, int val_offset, vector<int>& p) {
    if (len == 0) return;
    
    if (len == 1) {
        p[idx_offset + 1] = val_offset + 1;
        return;
    }

    int m = 1;
    while (2 * m <= len) m *= 2;

    if (m == len) return;

    p[idx_offset + len] = val_offset + m;

    
    for (int i = 1; i < len - m; ++i) {
        p[idx_offset + i] = val_offset + m + i;
        p[idx_offset + m + i] = val_offset + i;
    }

    
    p[idx_offset + len - m] = val_offset + len;

    
    construct(2 * m - len, idx_offset + len - m, val_offset + len - m, p);
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    int m = 1;
    while (2 * m <= n) m *= 2;

    if (m == n) {
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n + 1);
    construct(n, 0, 0, p);

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
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