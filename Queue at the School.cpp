#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

void solve() {
    int n, t;
    if (!(cin >> n >> t)) return;

    string s;
    cin >> s;

    for (int time = 0; time < t; ++time) {
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'B' && s[i+1] == 'G') {
                swap(s[i], s[i+1]);
                i++;
            }
        }
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}