#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    int max_val = -1, min_val = 101; 
    int max_i = 0, min_i = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        
        if (a[i] > max_val) {
            max_val = a[i];
            max_i = i;
        }
        
        if (a[i] <= min_val) {
            min_val = a[i];
            min_i = i;
        }
    }

    int moves = max_i + ((n - 1) - min_i);

    if (max_i > min_i) {
        moves--;
    }

    cout << moves << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}