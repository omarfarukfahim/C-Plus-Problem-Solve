#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int calculate_mex(const vector<int>& a) {
    int n = a.size();
    vector<bool> present(n + 2, false);
    
    for (int x : a) {
        if (x <= n + 1) {
            present[x] = true;
        }
    }
    
    int mex = 0;
    while (present[mex]) {
        mex++;
    }
    return mex;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int initial_mex = calculate_mex(a);

    int ans = min(initial_mex, k - 1);

    cout << ans << "\n"; 
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