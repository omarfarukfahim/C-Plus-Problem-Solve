#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Maximum value for k as per constraints (k <= 360)
const int MAXK = 365;

// dp_L[c] stores the minimum starting index L for the current level given cost c
int dp_L[MAXK];
// dp_score[c] stores the maximum happiness score achievable with cost c
long long dp_score[MAXK];

// Arrays to store the next state during DP transitions
int next_dp_L[MAXK];
long long next_dp_score[MAXK];

// Array to store the first friend index capable of carrying v cards
int first_occurrence[MAXK];

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Precompute first_occurrence[v]: the smallest index i (1-based) such that a[i] >= v.
    // If no friend can carry v cards, set to n + 1.
    for (int v = 1; v <= k; ++v) {
        first_occurrence[v] = n + 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= v) {
                first_occurrence[v] = i + 1;
                break;
            }
        }
    }

    // Initialize DP tables
    // Base case: For levels > k, the effective start index is n + 1 (meaning never active), cost is 0, score is 0.
    for (int c = 0; c <= k; ++c) {
        dp_L[c] = n + 1;
        dp_score[c] = -1; // -1 represents unreachable state
    }
    dp_score[0] = 0;

    // Process levels (values of cards) from k down to 1.
    // We calculate the contribution of each level v to the total happiness.
    // Contribution of level v = number of friends who see a max value >= v.
    for (int v = k; v >= 1; --v) {
        
        // Initialize next state arrays
        for (int c = 0; c <= k; ++c) {
            next_dp_L[c] = n + 1;
            next_dp_score[c] = -1;
        }

        for (int c = 0; c <= k; ++c) {
            if (dp_score[c] == -1) continue;

            int current_L = dp_L[c];
            long long current_S = dp_score[c];

            // Option 1: Do NOT assign value v explicitly to any friend.
            // In this case, the condition "max >= v" is only met if "max >= v+1" was met.
            // So the starting index for level v is the same as level v+1 (current_L).
            int new_L_1 = current_L;
            long long gain_1 = (new_L_1 <= n) ? (n - new_L_1 + 1) : 0;
            long long new_score_1 = current_S + gain_1;

            // Update next state for cost c
            if (new_score_1 > next_dp_score[c]) {
                next_dp_score[c] = new_score_1;
                next_dp_L[c] = new_L_1;
            } else if (new_score_1 == next_dp_score[c]) {
                if (new_L_1 < next_dp_L[c]) {
                    next_dp_L[c] = new_L_1;
                }
            }

            // Option 2: Assign value v to the earliest capable friend.
            // This costs v cards. The condition "max >= v" starts being met at min(current_L, first_occurrence[v]).
            if (c + v <= k) {
                int new_L_2 = min(current_L, first_occurrence[v]);
                long long gain_2 = (new_L_2 <= n) ? (n - new_L_2 + 1) : 0;
                long long new_score_2 = current_S + gain_2;
                int new_cost = c + v;

                // Update next state for cost c + v
                if (new_score_2 > next_dp_score[new_cost]) {
                    next_dp_score[new_cost] = new_score_2;
                    next_dp_L[new_cost] = new_L_2;
                } else if (new_score_2 == next_dp_score[new_cost]) {
                    if (new_L_2 < next_dp_L[new_cost]) {
                        next_dp_L[new_cost] = new_L_2;
                    }
                }
            }
        }

        // Move next state to current state for the next iteration
        for (int c = 0; c <= k; ++c) {
            dp_L[c] = next_dp_L[c];
            dp_score[c] = next_dp_score[c];
        }
    }

    // The answer is the maximum score possible with any valid cost <= k
    long long ans = 0;
    for (int c = 0; c <= k; ++c) {
        if (dp_score[c] > ans) {
            ans = dp_score[c];
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