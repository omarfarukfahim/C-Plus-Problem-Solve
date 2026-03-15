#include <iostream>

using namespace std;

void solve() {
    int x;
    if (!(cin >> x)) return;

    int count = 0;
    
    while (x > 0) {
        if (x & 1) {
            count++;
        }
        x >>= 1;
    }


    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}