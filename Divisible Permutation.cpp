#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> p;
    int curr = (n + 1) / 2;
    p.push_back(curr);

    int sign = (n % 2 == 0) ? 1 : -1;

    for (int i = 1; i < n; ++i) {
        curr += sign * i;
        p.push_back(curr);
        sign = -sign; 
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}