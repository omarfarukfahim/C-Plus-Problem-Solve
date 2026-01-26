#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cutoff_score = a[k - 1];
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= cutoff_score && a[i] > 0) {
            count++;
        } else {
            
            break;
        }
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}