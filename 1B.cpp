#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, l, r;
    if (!(cin >> n >> l >> r)) return;

    // p stores the prefix XOR sums
    vector<int> p(n + 1);
    
    // p[0] is always 0 by definition
    p[0] = 0;

    if (l == 1) {
        // We need p[r] == p[l-1] == p[0] == 0
        p[r] = 0;
        
        // Fill the rest with distinct values 1, 2, 3...
        int current_val = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == r) continue; // Skip r, it's already set to 0
            p[i] = current_val++;
        }
    } else {
        // We need p[r] == p[l-1]. We pick 1 (since 0 is taken by p[0])
        p[l - 1] = 1;
        p[r] = 1;
        
        // Fill the rest with distinct values 2, 3, 4...
        int current_val = 2;
        for (int i = 1; i <= n; ++i) {
            if (i == l - 1 || i == r) continue; // Skip these, they are set to 1
            p[i] = current_val++;
        }
    }

    // Recover array a from prefix XORs
    // a[i] = p[i] ^ p[i-1]
    for (int i = 1; i <= n; ++i) {
        cout << (p[i] ^ p[i - 1]) << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
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