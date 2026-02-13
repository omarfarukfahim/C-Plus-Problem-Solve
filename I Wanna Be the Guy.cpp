#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    set<int> levels;

    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int level;
        cin >> level;
        levels.insert(level);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int level;
        cin >> level;
        levels.insert(level);
    }

   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}