#include <iostream>
#include <algorithm> 

using namespace std;

void solve() {
    int n, m;
    if (cin >> n >> m) {
        int max_moves = min(n, m);

        if (max_moves % 2 != 0) {
            cout << "Akshat\n";
        } else {
            cout << "Malvika\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}