/**
 * Problem: A. Twins
 * Analysis:
 * We want to take the minimum number of coins such that our sum > remaining sum.
 * To achieve this efficiently (Greedy Strategy), we should always take the coins with the highest values first.
 * 1. Calculate the total sum of all coins.
 * 2. Sort the coins in descending order.
 * 3. Pick coins one by one, updating 'my_sum'.
 * 4. Stop when 'my_sum' > 'total_sum' - 'my_sum'.
 */

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

    // Sort in descending order to pick the largest coins first
    sort(a.begin(), a.end(), greater<int>());

    int my_sum = 0;
    int coin_count = 0;

    for (int i = 0; i < n; ++i) {
        my_sum += a[i];
        coin_count++;

        // Check if our sum is strictly greater than the sum of the remaining coins
        int remaining_sum = total_sum - my_sum;
        if (my_sum > remaining_sum) {
            break;
        }
    }

    cout << coin_count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}