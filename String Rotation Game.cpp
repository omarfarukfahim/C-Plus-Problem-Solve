#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int B = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[(i + 1) % n]) {
            B++;
        }
    }

    cout << min(n, B + 1) << "\n";
}

int main() {
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