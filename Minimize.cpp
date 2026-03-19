#include <iostream>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    cout << b - a << "\n";
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