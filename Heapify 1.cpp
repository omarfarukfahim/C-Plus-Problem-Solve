#include <iostream>
#include <vector>

using namespace std;


int get_odd_part(int n) {
    while ((n & 1) == 0) { 
        n >>= 1;           
    }
    return n;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    bool possible = true;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (get_odd_part(a[i]) != get_odd_part(i)) {
            possible = false;
            break; 
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}