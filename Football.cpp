#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    int consecutive_count = 1;
    bool dangerous = false;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i-1]) {
            consecutive_count++;
            if (consecutive_count >= 7) {
                dangerous = true;
                break;
            }
        } else {
            consecutive_count = 1;
        }
    }

    if (dangerous) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}