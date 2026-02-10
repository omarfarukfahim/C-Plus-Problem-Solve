#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> result(n + 1);

    for (int i = 1; i <= n; ++i) {
        int receiver;
        cin >> receiver;
        
        result[receiver] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cout << result[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}