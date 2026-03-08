#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_guarantee(long long x, int n, int m, long long l, const vector<long long>& a) {
    vector<long long> allowances(m, x);
    
    long long current_time = l;
    
    for (int i = n - 1; i >= 0; --i) {
        long long gap = current_time - a[i];
        
        for (long long step = 0; step < gap; ++step) {
            auto min_it = min_element(allowances.begin(), allowances.end());
            if (*min_it < 0) return false; 
            
            (*min_it)--;
        }
        
        auto min_it = min_element(allowances.begin(), allowances.end());
        if (*min_it < 0) return false;
        
        *min_it = a[i];
        
        current_time = a[i];
    }
    
    long long gap = current_time - 0;
    for (long long step = 0; step < gap; ++step) {
        auto min_it = min_element(allowances.begin(), allowances.end());
        if (*min_it < 0) return false;
        (*min_it)--;
    }
    
    auto min_it = min_element(allowances.begin(), allowances.end());
    return *min_it >= 0;
}

void solve() {
    int n, m;
    long long l;
    if (!(cin >> n >> m >> l)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long low = 0, high = l;
    long long ans = l;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (can_guarantee(mid, n, m, l, a)) {
            ans = mid;       
            high = mid - 1;
        } else {
            low = mid + 1;  
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