#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 3 == 0) {
        cout << "Second\n";
    } else {
        cout << "First\n";
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