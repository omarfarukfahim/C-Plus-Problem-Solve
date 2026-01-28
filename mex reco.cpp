/**
 * Problem: B. MEX Reordering
 * * Logic:
 * We want to order the array such that for every split point, MEX(Prefix) != MEX(Suffix).
 * * Simply SORTING the array works for all solvable cases.
 * * Why Sorting works:
 * The array becomes [0, 0...0, 1, 1...1, 2, ...].
 * 1. Split inside 0s:
 * Prefix = [0...0] -> MEX 1.
 * Suffix = [0...0, 1...1, ...] -> Contains 0 and 1 (if 1 exists) -> MEX >= 2.
 * (1 != 2) -> OK.
 * 2. Split after 0s:
 * Prefix = [0...0, ...] -> Contains 0 -> MEX >= 1.
 * Suffix = [1...1, ...] -> No 0 -> MEX 0.
 * (>=1 != 0) -> OK.
 * * Impossible Cases (Output NO):
 * 1. No zeros in input (MEX is always 0 vs 0).
 * 2. Multiple zeros AND no ones (Split inside zeros gives MEX 1 vs 1).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    int c0 = 0;
    int c1 = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) c0++;
        if (a[i] == 1) c1++;
    }

    // Failure Case 1: No zeros at all.
    // Failure Case 2: At least two zeros, but no ones to increase the Suffix MEX.
    if (c0 == 0 || (c0 >= 2 && c1 == 0)) {
        cout << "NO" << "\n";
        return;
    }

    // If solvable, sorting guarantees the condition.
    sort(a.begin(), a.end());

    cout << "YES" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
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