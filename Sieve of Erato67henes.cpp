#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    bool found_67 = false;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val == 67) {
            found_67 = true;
        }
    }

    if (found_67) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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