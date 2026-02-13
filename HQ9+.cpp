#include <iostream>
#include <string>

using namespace std;

void solve() {
    string p;
    if (!(cin >> p)) return;

    bool produces_output = false;
    for (char c : p) {
        if (c == 'H' || c == 'Q' || c == '9') {
            produces_output = true;
            break;
        }
    }

    if (produces_output) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}