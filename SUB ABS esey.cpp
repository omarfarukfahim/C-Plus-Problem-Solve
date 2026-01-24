#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> next_open(n, -1);
    int last = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '(') {
            last = i;
        }
        next_open[i] = last;
    }

    vector<int> suf_opens(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suf_opens[i] = suf_opens[i + 1] + (s[i] == '(' ? 1 : 0);
    }

    int max_len = -1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            if (i + 1 < n) {
                int j = next_open[i + 1];
                
                if (j != -1) {
                    int cnt = j - i;
                    
                    
                    if (suf_opens[j + 1] >= cnt) {
                        int current_len = n - 2 * cnt;
                        if (current_len > 0) { 
                            max_len = max(max_len, current_len);
                        }
                    }
                }
            }
        }
    }

    cout << max_len << "\n";
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