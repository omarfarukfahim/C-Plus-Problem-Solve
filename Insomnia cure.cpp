#include <iostream>

using namespace std;

void solve() {
    int k, l, m, n, d;
    if (!(cin >> k >> l >> m >> n >> d)) return;

    int damaged_dragons = 0;

    for (int i = 1; i <= d; ++i) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
            damaged_dragons++;
        }
    }

    cout << damaged_dragons << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}