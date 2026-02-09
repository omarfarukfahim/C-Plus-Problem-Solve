#include <iostream>

using namespace std;

void solve() {
    long long n;
    if (!(cin >> n)) return;

    if (n % 2 == 0) {
        cout << n / 2 << "\n";
    } else {
        cout << -(n + 1) / 2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}