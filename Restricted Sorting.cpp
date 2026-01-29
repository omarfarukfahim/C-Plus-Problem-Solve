#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const long long INF = 2e18; 
void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> visited;
    long long min_diff = INF;
    bool inversion_found = false;

    for (int x : a) {
        auto it = visited.upper_bound(x);
        
        if (it != visited.end()) {
            long long diff = (long long)(*it) - x;
            if (diff < min_diff) {
                min_diff = diff;
            }
            inversion_found = true;
            
            if (min_diff == 0) break;
        }
        
        
        
        
    }

    if (!inversion_found) {
        cout << -1 << "\n";
    } else {
        cout << min_diff << "\n";
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