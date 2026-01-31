#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int even_cnt = 0;
    int last_even_idx = 0;

    int odd_cnt = 0;
    int last_odd_idx = 0;

    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            even_cnt++;
            last_even_idx = i;
        } else {
            odd_cnt++;
            last_odd_idx = i;
        }
    }

    if (even_cnt == 1) {
        cout << last_even_idx << "\n";
    } else {
        cout << last_odd_idx << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}