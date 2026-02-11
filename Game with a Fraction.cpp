#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long p, q;
    if (!(cin >> p >> q)) return;

    long long diff = q - p;
    
    long long limit = min(p / 2, q / 3);

    if (diff >= 1 && diff <= limit) {
        cout << "Bob" << "\n";
    } else {
        cout << "Alice" << "\n";
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