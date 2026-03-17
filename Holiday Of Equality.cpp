#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    int max_welfare = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_welfare = max(max_welfare, a[i]);
    }

    long long total_spent = 0;
    
    for (int i = 0; i < n; ++i) {
        total_spent += (max_welfare - a[i]);
    }

    cout << total_spent << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}