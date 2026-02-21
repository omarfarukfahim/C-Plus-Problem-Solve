#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ones;
    vector<int> zeros;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones.push_back(i + 1);
        } else {
            zeros.push_back(i + 1);
        }
    }

    if (ones.size() % 2 == 0) {
        cout << ones.size() << "\n";
        for (int i = 0; i < ones.size(); ++i) {
            cout << ones[i] << (i + 1 == ones.size() ? "" : " ");
        }
        cout << "\n";
    } 
    else if (zeros.size() % 2 != 0) {
        cout << zeros.size() << "\n";
        for (int i = 0; i < zeros.size(); ++i) {
            cout << zeros[i] << (i + 1 == zeros.size() ? "" : " ");
        }
        cout << "\n";
    } 
    else {
        cout << -1 << "\n";
    }
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