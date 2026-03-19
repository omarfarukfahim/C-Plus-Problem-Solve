#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void solve() {
    int n, x;
    if (!(cin >> n >> x)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_dist = a[0] - 0;

    for (int i = 1; i < n; ++i) {
        max_dist = max(max_dist, a[i] - a[i - 1]);
    }

    int turnaround_dist = 2 * (x - a[n - 1]);
    max_dist = max(max_dist, turnaround_dist);

    cout << max_dist << "\n";
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