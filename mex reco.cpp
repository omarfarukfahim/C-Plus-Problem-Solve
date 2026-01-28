#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    int c0 = 0;
    int c1 = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) c0++;
        if (a[i] == 1) c1++;
    }

    if (c0 == 0 || (c0 >= 2 && c1 == 0)) {
        cout << "NO" << "\n";
        return;
    }

    sort(a.begin(), a.end());

    cout << "YES" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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