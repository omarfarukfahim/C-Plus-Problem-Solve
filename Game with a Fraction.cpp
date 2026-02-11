#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll p, q;
    if (!(cin >> p >> q)) return;

    ll K = min(p / 2, q / 3);

    if (K == 0) {
        cout << "Alice" << "\n";
        return;
    }

    ll X = p - 2 * K;
    ll Y = q - 3 * K;

    if (X == Y) {
        cout << "Bob" << "\n";
    } else {
        cout << "Alice" << "\n";
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