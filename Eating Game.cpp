#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    int max_val = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    int potential_winners = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == max_val) {
            potential_winners++;
        }
    }

    cout << potential_winners << "\n";
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