#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, x, y;
    if (!(cin >> n >> x >> y)) return;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> ac;
    vector<int> b;

    for (int i = 0; i < x; ++i) ac.push_back(p[i]);
    for (int i = x; i < y; ++i) b.push_back(p[i]);
    for (int i = y; i < n; ++i) ac.push_back(p[i]);

    auto min_it = min_element(b.begin(), b.end());
    vector<int> b_star(min_it, b.end());
    b_star.insert(b_star.end(), b.begin(), min_it);

    int k = 0;
    while (k < ac.size() && ac[k] < b_star[0]) {
        k++;
    }

    for (int i = 0; i < k; ++i) {
        cout << ac[i] << " ";
    }
    for (int i = 0; i < b_star.size(); ++i) {
        cout << b_star[i] << " ";
    }
    for (int i = k; i < ac.size(); ++i) {
        cout << ac[i] << " ";
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