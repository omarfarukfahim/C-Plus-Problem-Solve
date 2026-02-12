#include <iostream>

using namespace std;

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;

    if (a % b == 0) {
        cout << 0 << "\n";
    } else {
        cout << b - (a % b) << "\n";
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