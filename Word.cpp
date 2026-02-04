#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    int upper_cnt = 0;
    int lower_cnt = 0;

    for (char c : s) {
        if (isupper(c)) {
            upper_cnt++;
        } else {
            lower_cnt++;
        }
    }

    if (upper_cnt > lower_cnt) {
        for (size_t i = 0; i < s.length(); ++i) {
            s[i] = toupper(s[i]);
        }
    } else {
        for (size_t i = 0; i < s.length(); ++i) {
            s[i] = tolower(s[i]);
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