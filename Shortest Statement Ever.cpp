#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 4e18; 

ll dp[3][3];
ll next_dp[3][3];

struct Move {
    int u, v;
} choices[30][3][3];

void solve() {
    ll X, Y;
    if (!(cin >> X >> Y)) return;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            dp[i][j] = 0;

    for (int bit = 0; bit < 30; ++bit) {
        int bx = (X >> bit) & 1;
        int by = (Y >> bit) & 1;
        ll weight = (1LL << bit);

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                next_dp[i][j] = INF;

        for (int cx = 0; cx < 3; ++cx) {
            for (int cy = 0; cy < 3; ++cy) {
                
                int pairs[3][2] = {{0, 0}, {0, 1}, {1, 0}};

                for (auto& p : pairs) {
                    int u = p[0];
                    int v = p[1];

                    
                    
                    int ncx = cx; 
                    if (cx == 1) {
                        if (u < bx) ncx = 0;      
                        else if (u > bx) ncx = 2; 
                    }

                    int ncy = cy;
                    if (cy == 1) { 
                        if (v < by) ncy = 0;
                        else if (v > by) ncy = 2;
                    }

                    ll current_cost = 0;

                    if (ncx == 0) current_cost += (ll)(bx - u) * weight;
                    else if (ncx == 2) current_cost += (ll)(u - bx) * weight;

                    if (ncy == 0) current_cost += (ll)(by - v) * weight;
                    else if (ncy == 2) current_cost += (ll)(v - by) * weight;

                    ll total = current_cost + dp[ncx][ncy];

                    if (total < next_dp[cx][cy]) {
                        next_dp[cx][cy] = total;
                        choices[bit][cx][cy] = {u, v};
                    }
                }
            }
        }

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                dp[i][j] = next_dp[i][j];
    }

    ll p_out = 0;
    ll q_out = 0;
    int cur_cx = 1;
    int cur_cy = 1;

    for (int bit = 29; bit >= 0; --bit) {
        Move m = choices[bit][cur_cx][cur_cy];
        
        if (m.u) p_out |= (1LL << bit);
        if (m.v) q_out |= (1LL << bit);

        int bx = (X >> bit) & 1;
        int by = (Y >> bit) & 1;

        if (cur_cx == 1) {
            if (m.u < bx) cur_cx = 0;
            else if (m.u > bx) cur_cx = 2;
        }
        if (cur_cy == 1) {
            if (m.v < by) cur_cy = 0;
            else if (m.v > by) cur_cy = 2;
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