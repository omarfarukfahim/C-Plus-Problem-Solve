#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

namespace byteforge_omar {

    void execute_omar_logic() {
        int n;
        if (!(cin >> n)) return;

        vector<long long> a(n + 1);
        vector<int> y_orig(n + 2, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            y_orig[i] = (a[i] < 0 ? 1 : 0);
        }

        
        const long long OMAR_INF = -1e18;
        vector<vector<long long>> dp(n + 2, vector<long long>(2, OMAR_INF));
        vector<vector<int>> choice(n + 2, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = OMAR_INF;

        for (int i = 1; i <= n; i++) {
            for (int is_g = 0; is_g < 2; is_g++) {
                if (dp[i - 1][is_g] == OMAR_INF) continue;

                for (int y_fin = 0; y_fin < 2; y_fin++) {
                    if (!is_g && y_fin < y_orig[i]) continue;

                    int new_is_g = is_g | (y_fin > y_orig[i]);
                    long long val = abs(a[i]) * (y_fin == 0 ? 1 : -1);

                    if (dp[i - 1][is_g] + val > dp[i][new_is_g]) {
                        dp[i][new_is_g] = dp[i - 1][is_g] + val;
                        choice[i][new_is_g] = y_fin | (is_g << 1);
                    }
                }
            }
        }

        vector<int> y_final(n + 2, 0);
        int curr_is_g = (dp[n][1] > dp[n][0]) ? 1 : 0;

        for (int i = n; i >= 1; i--) {
            int state = choice[i][curr_is_g];
            y_final[i] = state & 1;
            curr_is_g = state >> 1;
        }

        vector<int> S;
        for (int i = 1; i <= n; i++) {
            int s_i = y_final[i] ^ y_final[i + 1] ^ y_orig[i] ^ y_orig[i + 1];
            if (s_i) {
                S.push_back(i);
            }
        }

        vector<int> omar_ops;
        vector<int> current_y = y_orig;
        
        vector<bool> used(n + 1, false);
        for (size_t step = 0; step < S.size(); step++) {
            for (int k : S) {
                if (!used[k] && current_y[k] == 0) {
                    omar_ops.push_back(k);
                    used[k] = true;
                    for (int j = 1; j <= k; j++) {
                        current_y[j] ^= 1;
                    }
                    break;
                }
            }
        }

        cout << omar_ops.size() << "\n";
        for (int i = 0; i < (int)omar_ops.size(); i++) {
            cout << omar_ops[i] << (i == (int)omar_ops.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    void execute_run() {
        int t;
        if (cin >> t) {
            while (t--) {
                execute_omar_logic();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    byteforge_omar::execute_run();

    return 0;
}