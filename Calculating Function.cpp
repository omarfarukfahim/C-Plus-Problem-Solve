/**
 * Problem: A. Calculating Function
 * Analysis:
 * The function f(n) represents an alternating sum.
 * Simulating the sum is too slow for n = 10^15.
 * We derived a pattern:
 * - If n is even, f(n) = n / 2.
 * - If n is odd, f(n) = -(n + 1) / 2.
 * We use 'long long' to handle large integers.
 */

#include <iostream>

using namespace std;

void solve() {
    long long n;
    if (!(cin >> n)) return;

    if (n % 2 == 0) {
        // Even case
        cout << n / 2 << "\n";
    } else {
        // Odd case
        // Using integer division, -(n+1)/2 works perfectly
        cout << -(n + 1) / 2 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}