#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    
    vector<long long> count(100005, 0);
    int max_val = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        count[x]++;
        max_val = max(max_val, x);
    }

    vector<long long> dp(max_val + 1, 0);

    dp[0] = 0;
    if (max_val >= 1) {
        dp[1] = count[1] * 1;
    }

    for (int i = 2; i <= max_val; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
    }

    cout << dp[max_val] << "\n";

    return 0;
}