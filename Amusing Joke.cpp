#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

void solve() {
    string guest, host, pile;
    
    if (!(cin >> guest >> host >> pile)) return;

    string combined_names = guest + host;

    sort(combined_names.begin(), combined_names.end());
    sort(pile.begin(), pile.end());

    if (combined_names == pile) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}