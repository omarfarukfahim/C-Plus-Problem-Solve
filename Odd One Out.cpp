#include <iostream>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b) {
        cout << c << "\n";
    } else if (a == c) {
        cout << b << "\n";
    } else {
        cout << a << "\n";
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