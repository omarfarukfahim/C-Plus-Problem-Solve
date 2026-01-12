#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long s, k, m;
    if (!(cin >> s >> k >> m)) return;

    long long interval_idx = (m / k) + 1;
    long long time_passed = m % k;
    long long start_sand;

    if (s <= k) {
        start_sand = s;
    } else {
        if (interval_idx % 2 != 0) {
            start_sand = s;
        } else {
            start_sand = k;
        }
    }

    long long ans = max(0LL, start_sand - time_passed);
    cout << ans << "\n";
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