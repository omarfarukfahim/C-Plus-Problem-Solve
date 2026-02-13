/**
 * Problem: A. I Wanna Be the Guy
 * Analysis:
 * We have n levels. We are given two lists of levels that Little X and Little Y can pass.
 * We need to check if the union of these two lists contains all numbers from 1 to n.
 * We can insert all levels from both lists into a set. If the set size is n, they can pass all levels.
 */

#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    set<int> levels;

    // Read Little X's levels
    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int level;
        cin >> level;
        levels.insert(level);
    }

    // Read Little Y's levels
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int level;
        cin >> level;
        levels.insert(level);
    }

    // Check if they can pass all n levels
    // Since the input levels are always between 1 and n, checking the size is sufficient.
    if (levels.size() == n) {
        cout << "I become the guy." << "\n";
    } else {
        cout << "Oh, my keyboard!" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}