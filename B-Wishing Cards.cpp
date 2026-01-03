#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Maximum value for k as per constraints (k <= 360)
const int MAXK = 365;

// dp[c][p] stores the maximum score using exactly cost 'c', 
// where the current starting index L is f[p].
// p is the index in the precomputed array 'f'.
// Using 'p' instead of the raw index L compresses the state space significantly.
long long dp[MAXK][MAXK];
long long max_S[MAXK]; // Auxiliary array to optimize transitions
int f[MAXK]; // f[v] stores the first friend index who can carry >= v cards

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Precompute f[v]: the smallest 1-based index i such that friend i can carry >= v cards.
    // If no friend can carry v cards, f[v] = n + 1.
    for (int v = 1; v <= k; ++v) {
        f[v] = n + 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= v) {
                f[v] = i + 1;
                break;
            }
        }
    }
    // Base case for the DP: level k+1 (virtual) starts at n+1.
    f[k + 1] = n + 1;

    // Initialize DP table with -1 (unreachable)
    for (int c = 0; c <= k; ++c) {
        for (int p = 0; p <= k + 1; ++p) {
            dp[c][p] = -1;
        }
    }

    // Base state: At level k+1, cost is 0, effective L is f[k+1] (which is index k+1 in f array)
    dp[0][k + 1] = 0;

    // Process levels from k down to 1
    for (int v = k; v >= 1; --v) {
        
        // Optimization: Pre-calculate the max score for each cost from the previous level (v+1)
        // This effectively represents the state before making a decision for level v.
        for (int c = 0; c <= k; ++c) {
            max_S[c] = -1;
            for (int p = v + 1; p <= k + 1; ++p) {
                if (dp[c][p] != -1) {
                    if (dp[c][p] > max_S[c]) {
                        max_S[c] = dp[c][p];
                    }
                }
            }
        }

        // Option 1: Do NOT buy a new card for this level.
        // We inherit the start index L from the previous level.
        // If the state was at p (meaning L = f[p]), it stays at p.
        // We add the contribution of level v given L = f[p].
        for (int c = 0; c <= k; ++c) {
            for (int p = v + 1; p <= k + 1; ++p) {
                if (dp[c][p] != -1) {
                    long long contribution = (f[p] <= n) ? (long long)n - f[p] + 1 : 0;
                    dp[c][p] += contribution;
                }
            }
        }

        // Option 2: BUY a new card for this level.
        // We pay 'v' cost to set the start index L = f[v].
        // This transitions from any valid state of the previous level to the new state p = v.
        long long buy_contribution = (f[v] <= n) ? (long long)n - f[v] + 1 : 0;
        
        for (int c = 0; c <= k - v; ++c) {
            if (max_S[c] != -1) {
                long long new_score = max_S[c] + buy_contribution;
                if (new_score > dp[c + v][v]) {
                    dp[c + v][v] = new_score;
                }
            }
        }
    }

    // The answer is the maximum score achievable with any valid cost <= k
    long long ans = 0;
    for (int c = 0; c <= k; ++c) {
        for (int p = 1; p <= k + 1; ++p) {
            if (dp[c][p] > ans) {
                ans = dp[c][p];
            }
        }
    }
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