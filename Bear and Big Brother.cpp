#include <iostream>

using namespace std;

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;

    int years = 0;

    while (a <= b) {
        a *= 3;
        b *= 2;
        years++;
    }

    cout << years << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}