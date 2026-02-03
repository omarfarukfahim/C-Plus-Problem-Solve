#include <iostream>
#include <algorithm> 

using namespace std;

void solve() {
    long long k, n, w;
    if (!(cin >> k >> n >> w)) return;

    long long total_cost = k * (w * (w + 1) / 2);

    long long borrow = total_cost - n;

    if (borrow < 0) {
        cout << 0 << "\n";
    } else {
        cout << borrow << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}