#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int moves = 0;

    while (n > 1) {
        if (n % 6 == 0) {
            n /= 6;
            moves++;
        } else if (n % 3 == 0) {
            n *= 2;
            moves++;
        } else {
            cout << -1 << "\n";
            return;
        }
    }

    cout << moves << "\n";
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