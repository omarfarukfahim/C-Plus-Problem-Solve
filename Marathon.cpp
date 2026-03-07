#include <iostream>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int count = 0;
    
    if (b > a) {
        count++;
    }
    if (c > a) {
        count++;
    }
    if (d > a) {
        count++;
    }

    cout << count << "\n";
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