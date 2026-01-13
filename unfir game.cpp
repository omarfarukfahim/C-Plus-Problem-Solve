#include <iostream>
#include <vector>

using namespace std;

long long C[65][65];

void precompute() {
    for (int i = 0; i <= 60; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

void solve() {
    long long n, k;
    if (!(cin >> n >> k)) return;

    int d = 0;
    long long temp = n;
    while (temp > 1) {
        temp >>= 1;
        d++;
    }

    long long ans = 0;

    for (int len = 1; len <= d; ++len) {
        int min_j = k - len + 1;
        if (min_j < 0) min_j = 0;

        for (int j = min_j; j <= len - 1; ++j) {
            ans += C[len - 1][j];
        }
    }

    if (d + 1 > k) {
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}