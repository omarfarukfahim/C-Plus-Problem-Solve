#include <iostream>
#include <cmath> 

using namespace std;

void solve() {
    int val;
    int r = 0, c = 0;
    
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> val;
            if (val == 1) {
                r = i;
                c = j;
            }
        }
    }

    int moves = abs(r - 3) + abs(c - 3);

    cout << moves << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}