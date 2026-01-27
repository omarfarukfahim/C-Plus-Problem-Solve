#include <iostream>

using namespace std;

void solve() {
    int m, n;
    if (!(cin >> m >> n)) return;

    int max_dominoes = (m * n) / 2;

    cout << max_dominoes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}