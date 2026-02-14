#include <iostream>
#include <algorithm> 
using namespace std;

void solve() {
    int a, b, c;
    if (!(cin >> a >> b >> c)) return;

    int ans = a + b + c;
    ans = max(ans, a * b * c);
    ans = max(ans, (a + b) * c);
    ans = max(ans, a * (b + c));

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}