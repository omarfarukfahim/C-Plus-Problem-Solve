#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, s, x;
    if (!(cin >> n >> s >> x)) return;
    
    int current_sum = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        current_sum += val;
    }
    
    if (current_sum > s) {
        cout << "NO" << "\n";
        return;
    }
    
    if ((s - current_sum) % x == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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