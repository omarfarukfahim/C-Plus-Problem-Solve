#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    bool accidental_caps = true;
    for (size_t i = 1; i < s.length(); ++i) {
        if (islower(s[i])) {
            accidental_caps = false;
            break; 
        }
    }

    if (accidental_caps) {
        for (size_t i = 0; i < s.length(); ++i) {
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}