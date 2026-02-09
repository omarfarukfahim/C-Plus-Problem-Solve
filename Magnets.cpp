/**
 * Problem: A. Magnets
 * Analysis:
 * We iterate through the sequence of magnets.
 * Whenever the current magnet is different from the previous one (e.g., changing from "10" to "01"),
 * it means like poles are touching (repulsion), starting a new group.
 * If they are the same ("10" and "10"), they attract and stay in the same group.
 */

#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int groups = 0;
    string prev = ""; 
    
    for (int i = 0; i < n; ++i) {
        string curr;
        cin >> curr;

        // If it's the first magnet, it starts the first group.
        if (i == 0) {
            groups++;
        } 
        // If current magnet is different from previous, a new group starts.
        else if (curr != prev) {
            groups++;
        }
        
        // Update previous to current for the next iteration
        prev = curr;
    }

    cout << groups << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}