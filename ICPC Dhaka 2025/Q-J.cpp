#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    int n = s.length();
    int len = 0;
    bool nul_found = false;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            // Regular character '0'
            if (!nul_found) {
                len++;
            }
        } else if (s[i] == '\\') {
            // Check for incomplete escape sequence (trailing backslash)
            if (i == n - 1) {
                cout << "INVALID" << "\n";
                return;
            }
            
            // Look ahead to the next character
            if (s[i+1] == '\\') {
                // Sequence: \\ (Backslash)
                if (!nul_found) {
                    len++;
                }
                i++; // Skip the next character as it's part of this sequence
            } else if (s[i+1] == '0') {
                // Sequence: \0 (NUL char)
                // strlen stops counting here, but we continue parsing to check for INVALID suffix
                nul_found = true;
                i++; // Skip the next character
            }
        }
    }
    
    cout << len << "\n";
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