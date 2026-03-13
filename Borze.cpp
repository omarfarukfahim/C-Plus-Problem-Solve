#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    string decoded_number = "";
    int i = 0;
    int n = s.length();

    while (i < n) {
        if (s[i] == '.') {
            decoded_number += '0';
            i++; 
        } else if (s[i] == '-') {
            if (s[i + 1] == '.') {
                decoded_number += '1';
            } else if (s[i + 1] == '-') {
                decoded_number += '2';
            }
            i += 2; 
        }
    }

    cout << decoded_number << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}