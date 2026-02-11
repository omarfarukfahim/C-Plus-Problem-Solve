#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long count = 0;

    for (int x = 1; x * x < n; ++x) {
        
        for (int j = 1; j <= n; ++j) {
            if (a[j] >= x) {
                long long dist = (long long)a[j] * x;
                if (dist < j) {
                    int i = j - (int)dist;
                    if (a[i] == x) {
                        count++;
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (a[i] > x) {
                long long dist = (long long)a[i] * x;
                if (i + dist <= n) {
                    int j = i + (int)dist;
                    if (a[j] == x) {
                        count++;
                    }
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