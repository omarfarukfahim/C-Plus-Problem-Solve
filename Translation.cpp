#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

void solve() {
    string s, t;
    if (!(cin >> s >> t)) return;

    string s_reversed = s;
    reverse(s_reversed.begin(), s_reversed.end());

    if (s_reversed == t) {
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