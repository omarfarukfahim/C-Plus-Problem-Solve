#include <iostream>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == k) {
            found = true;
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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