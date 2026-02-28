#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int s, n;
    if (!(cin >> s >> n)) return;

    vector<pair<int, int>> dragons(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> dragons[i].first >> dragons[i].second;
    }

    sort(dragons.begin(), dragons.end());

    bool can_win = true;
    for (int i = 0; i < n; ++i) {
        if (s > dragons[i].first) {
            s += dragons[i].second;
        } else {
            can_win = false;
            break;
        }
    }

    if (can_win) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}