/**
 * Problem: A. Fox And Snake
 * Analysis:
 * We iterate from row 1 to n.
 * - If the row number is odd (1, 3, 5...), print a full line of '#'.
 * - If the row number is even, we have two cases:
 * - Case 1 (Rows 2, 6, 10...): Print dots and end with a '#'.
 * Mathematically: row % 4 == 2.
 * - Case 2 (Rows 4, 8, 12...): Start with a '#' and print dots.
 * Mathematically: row % 4 == 0.
 */

#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    for (int r = 1; r <= n; ++r) {
        if (r % 2 != 0) {
            // Odd rows: Full body
            // Print m '#' characters
            for (int c = 0; c < m; ++c) cout << "#";
        } 
        else {
            // Even rows: Connecting body parts
            if (r % 4 == 2) {
                // Rows 2, 6, 10... -> Hash is on the RIGHT
                for (int c = 0; c < m - 1; ++c) cout << ".";
                cout << "#";
            } else {
                // Rows 4, 8, 12... -> Hash is on the LEFT (r % 4 == 0)
                cout << "#";
                for (int c = 0; c < m - 1; ++c) cout << ".";
            }
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}