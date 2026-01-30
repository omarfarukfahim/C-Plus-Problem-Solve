#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Point {
    ll x, y;
};

ll dist(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void solve() {
    int n;
    ll Ax, Ay, Bx, By;
    if (!(cin >> n >> Ax >> Ay >> Bx >> By)) return;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> y[i];

    map<ll, vector<ll>> groups;
    for (int i = 0; i < n; ++i) {
        groups[x[i]].push_back(y[i]);
    }

    
    Point prev_min = {Ax, Ay};
    Point prev_max = {Ax, Ay};
    ll dp_low = 0;
    ll dp_high = 0;

    for (auto& entry : groups) {
        ll curr_x = entry.first;
        vector<ll>& ys = entry.second;

        ll curr_min_y = ys[0];
        ll curr_max_y = ys[0];
        for (ll val : ys) {
            curr_min_y = min(curr_min_y, val);
            curr_max_y = max(curr_max_y, val);
        }

        Point curr_min_pt = {curr_x, curr_min_y};
        Point curr_max_pt = {curr_x, curr_max_y};
        
        ll internal_dist = curr_max_y - curr_min_y;

        ll to_low_from_prev_low = dp_low + dist(prev_min, curr_max_pt) + internal_dist;
        ll to_low_from_prev_high = dp_high + dist(prev_max, curr_max_pt) + internal_dist;
        ll next_dp_low = min(to_low_from_prev_low, to_low_from_prev_high);

        ll to_high_from_prev_low = dp_low + dist(prev_min, curr_min_pt) + internal_dist;
        ll to_high_from_prev_high = dp_high + dist(prev_max, curr_min_pt) + internal_dist;
        ll next_dp_high = min(to_high_from_prev_low, to_high_from_prev_high);

        dp_low = next_dp_low;
        dp_high = next_dp_high;
        prev_min = curr_min_pt;
        prev_max = curr_max_pt;
    }

    Point end_pt = {Bx, By};
    ll ans = min(dp_low + dist(prev_min, end_pt), dp_high + dist(prev_max, end_pt));

    cout << ans << "\n";
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