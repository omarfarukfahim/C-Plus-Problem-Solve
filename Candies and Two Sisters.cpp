#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int ans = (n - 1) / 2;
    
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