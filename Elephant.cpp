#include <iostream>

using namespace std;

void solve() {
    int x;
    if (!(cin >> x)) return;

    int steps = (x + 4) / 5;

    cout << steps << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}