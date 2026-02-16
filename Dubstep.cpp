#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    bool space_needed = false;
    bool printed_first_word = false;

    for (int i = 0; i < s.length(); ) {
        if (i + 2 < s.length() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i += 3; 
            space_needed = true; 
        } else {
            
            if (space_needed && printed_first_word) {
                cout << " ";
                space_needed = false; 
            }
            
            cout << s[i];
            printed_first_word = true;
            space_needed = false; 
            i++;
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}