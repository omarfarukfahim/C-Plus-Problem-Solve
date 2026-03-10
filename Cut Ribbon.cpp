#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, a, b, c;
    if (!(cin >> n >> a >> b >> c)) return;

    vector<int> dp(n + 1, -1e9);
    
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (i >= a) dp[i] = max(dp[i], dp[i - a] + 1);
        if (i >= b) dp[i] = max(dp[i], dp[i - b] + 1);
        if (i >= c) dp[i] = max(dp[i], dp[i - c] + 1);
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}