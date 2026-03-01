#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> f(m);
    for (int i = 0; i < m; ++i) {
        cin >> f[i];
    }

    sort(f.begin(), f.end());

    int min_diff = 1005; 

    for (int i = 0; i <= m - n; ++i) {
        int current_diff = f[i + n - 1] - f[i];
        
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    cout << min_diff << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}