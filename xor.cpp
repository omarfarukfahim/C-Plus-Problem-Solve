#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct Interval {
    ll l, r;
    bool operator==(const Interval& other) const {
        return l == other.l && r == other.r;
    }
};

struct IntervalSet {
    int count = 0;
    Interval vals[2]; 

    void add(ll l, ll r) {
        if (l > r) return;
        if (count > 0 && vals[count - 1].r + 1 >= l) {
            vals[count - 1].r = max(vals[count - 1].r, r);
        } else {
            if (count < 2) {
                vals[count++] = {l, r};
            }
        }
    }
};

ll solve_recursive(int bit, const IntervalSet& intervals) {
    if (intervals.count == 0) {
        return (1LL << (bit + 1));
    }

    ll mask = (1LL << (bit + 1)) - 1;
    if (intervals.count == 1 && intervals.vals[0].l == 0 && intervals.vals[0].r == mask) {
        return (1LL << (bit + 1));
    }

    if (bit < 0) return 1;

    ll mid = (1LL << bit);

    IntervalSet L_parts;
    IntervalSet R_parts;
    IntervalSet next_intervals;

    for (int i = 0; i < intervals.count; ++i) {
        ll l = intervals.vals[i].l;
        ll r = intervals.vals[i].r;

        if (l < mid) {
            ll end = (r < mid - 1) ? r : (mid - 1);
            L_parts.add(l, end);
            next_intervals.add(l, end);
        }
        
        if (r >= mid) {
            ll start = (l > mid) ? l : mid;
            ll shifted_start = start - mid;
            ll shifted_end = r - mid;
            R_parts.add(shifted_start, shifted_end);
            next_intervals.add(shifted_start, shifted_end);
        }
    }

    bool can_swap = true;
    if (L_parts.count != R_parts.count) {
        can_swap = false;
    } else {
        for (int i = 0; i < L_parts.count; ++i) {
            if (!(L_parts.vals[i] == R_parts.vals[i])) {
                can_swap = false;
                break;
            }
        }
    }

    ll res = solve_recursive(bit - 1, next_intervals);

    if (can_swap) {
        return res * 2;
    } else {
        return res;
    }
}

void solve() {
    ll l, r;
    if (!(cin >> l >> r)) return;

    if (l == r) {
        cout << 0 << "\n";
        return;
    }

    ll xor_val = l ^ r;
    int msb = 63 - __builtin_clzll(xor_val);

    ll mask = (1LL << (msb + 1)) - 1;
    l &= mask;
    r &= mask;

    IntervalSet init;
    init.add(l, r);

    cout << solve_recursive(msb, init) - 1 << "\n";
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