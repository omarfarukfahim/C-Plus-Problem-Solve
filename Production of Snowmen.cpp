#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    // Use 0-based indexing for easier modulo arithmetic
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    // Helper lambda to count valid cyclic shifts between two arrays
    auto count_valid_shifts = [&](const vector<int>& lower, const vector<int>& upper) {
        int valid_count = 0;
        // Try every possible shift 's'
        for (int s = 0; s < n; ++s) {
            bool possible = true;
            // Check condition for all elements
            for (int i = 0; i < n; ++i) {
                // lower[i] must be < upper[(i + s) % n]
                if (lower[i] >= upper[(i + s) % n]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                valid_count++;
            }
        }
        return valid_count;
    };

    // 1. Find number of valid shifts between A and B
    long long valid_ab = count_valid_shifts(a, b);

    // 2. Find number of valid shifts between B and C
    long long valid_bc = count_valid_shifts(b, c);

    // 3. Total combinations
    // For every valid shift x (A->B) and valid shift y (B->C),
    // we have established a rigid relative configuration.
    // We can rotate this entire configuration n times (starting index i can be 1..n).
    long long ans = n * valid_ab * valid_bc;

    cout << ans << "\n";
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