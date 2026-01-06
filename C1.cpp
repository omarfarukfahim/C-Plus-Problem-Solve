#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n), b(n);
    int xor_a = 0;
    int xor_b = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        xor_a ^= a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        xor_b ^= b[i];
    }

    // Tie Condition: If XOR sums are equal initially, 
    // any swap flips both, so they remain equal.
    if (xor_a == xor_b) {
        cout << "Tie\n";
        return;
    }

    // If XOR sums are different, one is 1 and the other is 0.
    // The winner is determined by who makes the last meaningful move.
    // A meaningful move is available at index i if a[i] != b[i].
    
    int last_diff_index = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            last_diff_index = i + 1; // 1-based index
        }
    }

    if (last_diff_index % 2 != 0) {
        // Last meaningful move is at an odd index -> Ajisai controls the final state
        cout << "Ajisai\n";
    } else {
        // Last meaningful move is at an even index -> Mai controls the final state
        cout << "Mai\n";
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