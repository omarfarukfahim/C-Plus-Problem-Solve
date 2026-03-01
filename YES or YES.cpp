#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        s[i] = toupper(s[i]);
    }

    if (s == "YES") {
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