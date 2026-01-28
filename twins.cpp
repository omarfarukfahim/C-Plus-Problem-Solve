#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int my_sum = 0;
    int coin_count = 0;

    for (int i = 0; i < n; ++i) {
        my_sum += a[i];
        coin_count++;

        int remaining_sum = total_sum - my_sum;
        if (my_sum > remaining_sum) {
            break;
        }
    }

    cout << coin_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}