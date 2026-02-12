#include <iostream>
#include <set>

using namespace std;

void solve() {
    set<int> colors;
    
    for (int i = 0; i < 4; ++i) {
        int s;
        if (cin >> s) {
            colors.insert(s);
        }
    }

    int to_buy = 4 - colors.size();

    cout << to_buy << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}