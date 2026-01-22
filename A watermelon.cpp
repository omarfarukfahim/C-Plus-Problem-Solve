#include <iostream>

using namespace std;

void solve() {
    int w;
    if (!(cin >> w)) return;

    if (w % 2 == 0 && w > 2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}