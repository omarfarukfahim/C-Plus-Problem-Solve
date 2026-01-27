#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int valid_rooms_count = 0;

    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        
        if (q - p >= 2) {
            valid_rooms_count++;
        }
    }

    cout << valid_rooms_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}