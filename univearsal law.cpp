#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, h, l;
    if (!(cin >> n >> h >> l)) return;

    int count_U = 0; 
    int count_R = 0; 
    int count_C = 0; 
    
    int min_dim = min(h, l);

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        
        if (val <= min_dim) {
            count_U++;
        } else if (val <= h) {
            count_R++;
        } else if (val <= l) {
            count_C++;
        }
    }

    int pairs = 0;

    int match_RC = min(count_R, count_C);
    pairs += match_RC;
    count_R -= match_RC;
    count_C -= match_RC;

    int leftover_needs = count_R + count_C;
    
    int match_with_U = min(leftover_needs, count_U);
    pairs += match_with_U;
    count_U -= match_with_U;

    pairs += count_U / 2;

    cout << pairs << "\n";
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