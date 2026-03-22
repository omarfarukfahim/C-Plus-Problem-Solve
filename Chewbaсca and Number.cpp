#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    for (int i = 0; i < s.length(); ++i) {
        int current_digit = s[i] - '0';
        
        int inverted_digit = 9 - current_digit;

        if (inverted_digit < current_digit) {
            if (i == 0 && current_digit == 9) {
                continue; 
            }
            s[i] = inverted_digit + '0';
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