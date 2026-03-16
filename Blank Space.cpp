#include <iostream>
#include <algorithm> 

using namespace std;

void solve() {
    int n;
    cin >> n;

    int max_zeros = 0;
    int current_zeros = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        
        if (a == 0) {
            current_zeros++;
        } else {
            max_zeros = max(max_zeros, current_zeros);
            current_zeros = 0;
        }
    }
    
    max_zeros = max(max_zeros, current_zeros);

    cout << max_zeros << "\n";
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