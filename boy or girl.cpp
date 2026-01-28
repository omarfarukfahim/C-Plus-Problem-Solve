/**
 * Problem: A. Boy or Girl
 * Analysis:
 * We need to count the number of unique characters in the input string.
 * A std::set is perfect for this as it stores only unique elements.
 * If the set size is even, print "CHAT WITH HER!".
 * If the set size is odd, print "IGNORE HIM!".
 */

#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    // Use a set to store unique characters
    set<char> distinct_chars;
    for (char c : s) {
        distinct_chars.insert(c);
    }

    // Check if the number of distinct characters is even or odd
    if (distinct_chars.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << "\n";
    } else {
        cout << "IGNORE HIM!" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}