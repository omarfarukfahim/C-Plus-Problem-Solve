#include <iostream>

using namespace std;

void solve() {
    int k, r;
    if (!(cin >> k >> r)) return;

    for (int i = 1; i <= 10; ++i) {
        int total_cost = i * k;
        
        if (total_cost % 10 == 0 || total_cost % 10 == r) {
            cout << i << "\n";
            break; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}