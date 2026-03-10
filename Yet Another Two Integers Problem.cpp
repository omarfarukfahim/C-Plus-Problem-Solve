#include <iostream>
#include <cmath> 

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    long long diff = abs(a - b);

    long long moves = diff / 10;

    if (diff % 10 != 0) {
        moves++;
    }

    cout << moves << "\n";
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