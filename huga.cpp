#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    if (!(cin >> n >> k)) return;

    if (n < k) {
        cout << -1 << "\n";
        return;
    }
    
    ll min_val = n;
    ll max_val = n;
    
    for (int t = 0; t <= 65; ++t) {
        if (k >= min_val && k <= max_val) {
            cout << t << "\n";
            return;
        }

        if (max_val < k) {
            cout << -1 << "\n";
            return;
        }

        min_val = min_val / 2;
        max_val = (max_val + 1) / 2;
        
        if (max_val == 0 && k > 0) {
             cout << -1 << "\n";
             return;
        }
    }
    
    cout << -1 << "\n";
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