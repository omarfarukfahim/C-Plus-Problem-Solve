#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int implemented_problems = 0;

    for (int i = 0; i < n; ++i) {
        int p, v, t;
        cin >> p >> v >> t;
        
        if (p + v + t >= 2) {
            implemented_problems++;
        }
    }

    cout << implemented_problems << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}