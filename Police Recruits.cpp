#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int available_officers = 0;
    int untreated_crimes = 0;

    for (int i = 0; i < n; ++i) {
        int event;
        cin >> event;

        if (event > 0) {
            available_officers += event;
        } else if (event == -1) {
            if (available_officers > 0) {
                available_officers--;
            } else {
                untreated_crimes++;
            }
        }
    }

    cout << untreated_crimes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}