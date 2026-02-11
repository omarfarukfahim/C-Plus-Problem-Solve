#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    
    
    vector<vector<int>> positions(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= n) {
            positions[a[i]].push_back(i);
        }
    }

    long long count = 0;
    
    for (int v = 1; v * v < 2 * n; ++v) { 
        if (v > n) break; 
        
        for (int i : positions[v]) {
            
            for (int y = v; ; ++y) {
                long long product = (long long)v * y;
                if (product >= n) break; 
                
                int j = i + (int)product;
                if (j > n) break;
                
                if (a[j] == y) {
                    count++;
                }
            }

            for (int y = v + 1; ; ++y) {
                long long product = (long long)v * y;
                if (product >= n) break; 
                
                int left = i - (int)product;
                if (left < 1) break;
                
                if (a[left] == y) {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";
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