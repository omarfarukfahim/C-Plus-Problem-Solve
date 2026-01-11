#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Friend {
    int id;
    long long x, y, z;
    long long diff; 
};

void solve() {
    int n, m;
    long long k;
    if (!(cin >> n >> m >> k)) return;

    vector<long long> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    vector<Friend> friends(n);
    long long sum_y = 0;
    for (int i = 0; i < n; ++i) {
        friends[i].id = i;
        cin >> friends[i].x >> friends[i].y >> friends[i].z;
        friends[i].diff = friends[i].z - friends[i].y;
        sum_y += friends[i].y;
    }

    sort(friends.begin(), friends.end(), [](const Friend& a, const Friend& b) {
        return a.x > b.x;
    });

    long long rem_k = k - sum_y;
    if (rem_k < 0) {
        cout << 0 << "\n";
        return;
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    vector<long long> money_costs;

    int box_idx = 0;
    int available_boxes = 0;

    for (int i = 0; i < n; ++i) {
        long long req = friends[i].x;

        while (box_idx < m && a[box_idx] >= req) {
            available_boxes++;
            box_idx++;
        }

        pq.push(friends[i].diff);

        if ((int)pq.size() > available_boxes) {
            long long cheapest_diff = pq.top();
            pq.pop();
            money_costs.push_back(cheapest_diff);
        }
    }

    int happy_count = pq.size();

    sort(money_costs.begin(), money_costs.end());
    for (long long cost : money_costs) {
        if (rem_k >= cost) {
            rem_k -= cost;
            happy_count++;
        } else {
            break;
        }
    }

    cout << happy_count << "\n";
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