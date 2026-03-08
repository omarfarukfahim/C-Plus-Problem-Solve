#include <iostream>
#include <algorithm> 

using namespace std;

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;

    int different_days = min(a, b);

    int remaining_socks = max(a, b) - different_days;

    int same_days = remaining_socks / 2;

    cout << different_days << " " << same_days << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}