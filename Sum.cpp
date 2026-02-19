#include <iostream>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b + c || b == a + c || c == a + b) {
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