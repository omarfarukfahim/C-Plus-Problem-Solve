#include <iostream>
#include <algorithm> 

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        if (s == 1) c1++;
        else if (s == 2) c2++;
        else if (s == 3) c3++;
        else if (s == 4) c4++;
    }

    int taxis = c4;

    taxis += c3;
    c1 = max(0, c1 - c3);

    taxis += c2 / 2;
    
    if (c2 % 2 != 0) {
        taxis++;
        c1 = max(0, c1 - 2);
    }

    taxis += (c1 + 3) / 4;

    cout << taxis << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}