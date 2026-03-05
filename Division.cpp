/**
 * Problem: A. Division?
 * Analysis:
 * We need to output the correct division based on the user's rating.
 * We can use an if-else ladder starting from the highest rating threshold
 * down to the lowest to naturally handle the upper bounds of each division.
 */

#include <iostream>

using namespace std;

void solve() {
    int rating;
    // Read the rating for the current test case
    cin >> rating;

    // Check conditions from highest division to lowest
    if (rating >= 1900) {
        cout << "Division 1\n";
    } else if (rating >= 1600) {
        // We already know rating < 1900 if we reach here
        cout << "Division 2\n";
    } else if (rating >= 1400) {
        // We already know rating < 1600 if we reach here
        cout << "Division 3\n";
    } else {
        // We already know rating < 1400 if we reach here
        cout << "Division 4\n";
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}