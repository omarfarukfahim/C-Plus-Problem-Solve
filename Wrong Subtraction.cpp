#include <iostream>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    for (int i = 0; i < k; ++i) {
        if (n % 10 != 0) {
            n--;
        } else {
            n /= 10;
        }
    }

    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}