#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            cout << " that ";
        }

        if (i % 2 != 0) {
            cout << "I hate";
        } else {
            cout << "I love";
        }
    }

    cout << " it" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}