#include <iostream>
#include <algorithm> 

using namespace std;

void solve() {
    int n, m, a, b;
    if (!(cin >> n >> m >> a >> b)) return;

    int cost_all_singles = n * a;

    int bundles_needed = n / m;
    int leftover_rides = n % m;
    
    int leftover_cost = min(leftover_rides * a, b);
    
    int cost_with_bundles = (bundles_needed * b) + leftover_cost;

    cout << min(cost_all_singles, cost_with_bundles) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}