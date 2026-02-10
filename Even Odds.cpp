#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    if (!(cin >> n >> k)) return;

    long long odd_count = (n + 1) / 2;

    if (k <= odd_count) {
        cout << (k * 2) - 1 << "\n";
    } else {
        long long even_index = k - odd_count;
        cout << even_index * 2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}