#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    string s;
    cin >> s;

    int remove_count = 0;

    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            remove_count++;
        }
    }

    cout << remove_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}