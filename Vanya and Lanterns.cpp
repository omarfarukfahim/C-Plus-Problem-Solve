#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve() {
    int n;
    long long l;
    
    if (!(cin >> n >> l)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long max_gap = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] - a[i] > max_gap) {
            max_gap = a[i + 1] - a[i];
        }
    }

    double req_between = max_gap / 2.0;
    double req_start = a[0];
    double req_end = l - a[n - 1];

    double d = max({req_between, req_start, req_end});

    cout << fixed << setprecision(10) << d << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}