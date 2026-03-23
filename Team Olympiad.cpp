#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> v1, v2, v3;

    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            v1.push_back(i);
        } else if (t == 2) {
            v2.push_back(i);
        } else if (t == 3) {
            v3.push_back(i);
        }
    }

    int w = min({v1.size(), v2.size(), v3.size()});
    
    cout << w << "\n";

    for (int i = 0; i < w; ++i) {
        cout << v1[i] << " " << v2[i] << " " << v3[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}