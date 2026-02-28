#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> x(3);
    
    if (!(cin >> x[0] >> x[1] >> x[2])) return;

    sort(x.begin(), x.end());

    int min_distance = x[2] - x[0];

    cout << min_distance << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}