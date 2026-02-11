#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> p(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> blocks;
    vector<bool> seen(n + 1, false);
    
    if (n > 0) {
        blocks.push_back(a[0]);
        seen[a[0]] = true;
    }
    
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1]) {
            if (seen[a[i]]) {
                cout << "NO" << "\n";
                return;
            }
            blocks.push_back(a[i]);
            seen[a[i]] = true;
        }
    }

    for (size_t i = 0; i + 1 < blocks.size(); ++i) {
        int val1 = blocks[i];
        int val2 = blocks[i+1];
        
        if (pos[val1] > pos[val2]) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
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