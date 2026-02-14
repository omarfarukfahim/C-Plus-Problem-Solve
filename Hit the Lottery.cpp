#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int bills = 0;
    
    int denominations[] = {100, 20, 10, 5, 1};

    for (int coin : denominations) {
        bills += n / coin;
        n %= coin;
    }

    cout << bills << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}