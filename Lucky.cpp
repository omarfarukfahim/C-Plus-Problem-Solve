#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int sum_first_half = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    
    int sum_last_half = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');

    if (sum_first_half == sum_last_half) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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