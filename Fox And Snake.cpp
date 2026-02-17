#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    for (int r = 1; r <= n; ++r) {
        if (r % 2 != 0) {
            for (int c = 0; c < m; ++c) cout << "#";
        } 
        else {
            if (r % 4 == 2) {
                for (int c = 0; c < m - 1; ++c) cout << ".";
                cout << "#";
            } else {
                cout << "#";
                for (int c = 0; c < m - 1; ++c) cout << ".";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}