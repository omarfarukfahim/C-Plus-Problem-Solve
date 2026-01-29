#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 4e18; 

ll dp[32][3][3];
struct Move { int u, v; } parent[32][3][3];

int visited[32][3][3];
int tc_id = 0; 

ll X, Y;

ll solve(int bit, int cx, int cy) {
    if (bit < 0) return 0;
    
    if (visited[bit][cx][cy] == tc_id) return dp[bit][cx][cy];

    ll res = INF;
    Move best_move = {-1, -1};

    int bx = (X >> bit) & 1;
    int by = (Y >> bit) & 1;
    ll weight = (1LL << bit);

    int pairs[3][2] = {{0, 0}, {0, 1}, {1, 0}};

    for (int k = 0; k < 3; ++k) {
        int u = pairs[k][0];
        int v = pairs[k][1];

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

        ll sub_res = solve(bit - 1, ncx, ncy);
        
        if (sub_res != INF) {
            if (current_cost + sub_res < res) {
                res = current_cost + sub_res;
                best_move = {u, v};
            }
        }
    }

    visited[bit][cx][cy] = tc_id;
    parent[bit][cx][cy] = best_move;
    return dp[bit][cx][cy] = res;
}

void run_test_case() {
    if (!(cin >> X >> Y)) return;

    tc_id++;

    solve(29, 1, 1);

    ll P = 0, Q = 0;
    int cx = 1, cy = 1;

    for (int bit = 29; bit >= 0; --bit) {
        Move m = parent[bit][cx][cy];
        if (m.u) P |= (1LL << bit);
        if (m.v) Q |= (1LL << bit);

        int bx = (X >> bit) & 1;
        int by = (Y >> bit) & 1;

        if (cx == 1) {
            if (m.u < bx) cx = 0;
            else if (m.u > bx) cx = 2;
        }
        if (cy == 1) {
            if (m.v < by) cy = 0;
            else if (m.v > by) cy = 2;
        }
    }

    cout << P << " " << Q << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            run_test_case();
        }
    }
    return 0;
}