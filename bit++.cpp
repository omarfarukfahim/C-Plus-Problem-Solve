#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int x = 0;
    string statement;

    while (n--) {
        cin >> statement;
        
        if (statement[1] == '+') {
            x++;
        } else {
            x--;
        }
    }

    cout << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}