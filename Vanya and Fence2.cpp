#include <iostream>

using namespace std;

void solve() {
    int n, h;
    if (!(cin >> n >> h)) return;

    int total_width = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a > h) {
            total_width += 2;
        } else {
            total_width += 1;
        }
    }

    cout << total_width << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}