#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(long long S, long long n, long long m, long long k) {
    if (S == 0) return true; 

    long long limit = m + 1 - S;

    if (limit < 0) return false;

    long long min_L_geo = max(0LL, S - (n - k));
    long long max_L_geo = min(S, k - 1);

    long long min_L_time = S - limit;
    long long max_L_time = limit;

    long long final_min_L = max(min_L_geo, min_L_time);
    long long final_max_L = min(max_L_geo, max_L_time);

    return final_min_L <= final_max_L;
}

void solve() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;

    long long low = 1, high = n;
    long long ans = 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid - 1, n, m, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

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