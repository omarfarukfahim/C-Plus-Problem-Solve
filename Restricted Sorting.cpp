#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(long long k, int n, const vector<int>& a, const vector<int>& b) {
    int min_val = b[0];      
    int max_val = b[n - 1];  

    if ((long long)max_val - min_val < k) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    long long lower_bound = max_val - k;
    long long upper_bound = min_val + k;

    for (int i = 0; i < n; ++i) {
        if (a[i] > lower_bound && a[i] < upper_bound) {
            if (a[i] != b[i]) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    long long low = 0, high = 1000000000LL; 
    long long ans = 0;

    bool already_sorted = true;
    for(int i=0; i<n; ++i) {
        if(a[i] != b[i]) {
            already_sorted = false;
            break;
        }
    }
    if (already_sorted) {
        cout << -1 << "\n";
        return;
    }

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, a, b)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

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