#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int tens_digit = n / 10;
    int units_digit = n % 10;

    cout << tens_digit + units_digit << "\n";
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