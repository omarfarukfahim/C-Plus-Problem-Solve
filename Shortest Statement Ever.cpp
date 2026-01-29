#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 4e18; 

ll memo[32][3][3];
struct Choice {
    int p_val, q_val;
};
Choice choices[32][3][3];

ll x_in, y_in;

ll solve_dp(int bit, int sx, int sy) {
    if (bit < 0) return 0;
    if (memo[bit][sx][sy] != -1) return memo[bit][sx][sy];

    ll best_cost = INF;
    Choice best_choice = {-1, -1};

    int bx = (x_in >> bit) & 1;
    int by = (y_in >> bit) & 1;

    int pairs[3][2] = {{0,0}, {0,1}, {1,0}};

    for (auto& p : pairs) {
        int u = p[0]; 
        int v = p[1]; 

        int nsx = sx;
        if (sx == 1) { 
            if (u < bx) nsx = 0;      
            else if (u > bx) nsx = 2; 
        }

        int nsy = sy;
        if (sy == 1) {
            if (v < by) nsy = 0;
            else if (v > by) nsy = 2;
        }

        ll current_cost = 0;
        ll weight = 1LL << bit;

        if (nsx == 0) current_cost += (ll)(bx - u) * weight; 
        else if (nsx == 2) current_cost += (ll)(u - bx) * weight; 
        if (nsy == 0) current_cost += (ll)(by - v) * weight; 
        else if (nsy == 2) current_cost += (ll)(v - by) * weight; 

        ll remaining = solve_dp(bit - 1, nsx, nsy);
        
        if (remaining != INF) {
            ll total = current_cost + remaining;
            if (total < best_cost) {
                best_cost = total;
                best_choice = {u, v};
            }
        }
    }

    choices[bit][sx][sy] = best_choice;
    return memo[bit][sx][sy] = best_cost;
}

void solve() {
    if (!(cin >> x_in >> y_in)) return;

    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                memo[i][j][k] = -1;

    solve_dp(30, 1, 1);

    ll p_out = 0;
    ll q_out = 0;
    int curr_sx = 1;
    int curr_sy = 1;

    for (int bit = 30; bit >= 0; --bit) {
        Choice c = choices[bit][curr_sx][curr_sy];
        if (c.p_val) p_out |= (1LL << bit);
        if (c.q_val) q_out |= (1LL << bit);

        int bx = (x_in >> bit) & 1;
        int by = (y_in >> bit) & 1;

        if (curr_sx == 1) {
            if (c.p_val < bx) curr_sx = 0;
            else if (c.p_val > bx) curr_sx = 2;
        }
        if (curr_sy == 1) {
            if (c.q_val < by) curr_sy = 0;
            else if (c.q_val > by) curr_sy = 2;
        }
    }

    cout << p_out << " " << q_out << "\n";
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