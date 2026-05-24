#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace omar_exclusive {

    bool check_omar_target(int X, int n, const vector<int>& omar_a, const vector<int>& omar_b) {
        vector<int> omar_w;
        
        for (int i = 0; i < n; i++) {
            int v = (omar_a[i] >= X ? 1 : 0) + (omar_b[i] >= X ? 1 : 0);
            int w = v - 1;
            if (w != 0) {
                omar_w.push_back(w);
            }
        }
        
        int omar_count_1 = 0;
        int omar_count_minus_1_blocks = 0;
        bool omar_in_minus_1_streak = false;
        
        for (int weight : omar_w) {
            if (weight == 1) {
                omar_count_1++;
                omar_in_minus_1_streak = false;
            } else if (weight == -1) {
                if (!omar_in_minus_1_streak) {
                    omar_count_minus_1_blocks++;
                    omar_in_minus_1_streak = true;
                }
            }
        }
        
        return omar_count_1 > omar_count_minus_1_blocks;
    }

    void execute_omar_solve() {
        int n;
        cin >> n;
        
        vector<int> omar_a(n), omar_b(n);
        int omar_max_val = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> omar_a[i];
            omar_max_val = max(omar_max_val, omar_a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> omar_b[i];
            omar_max_val = max(omar_max_val, omar_b[i]);
        }
        
        int omar_left = 1, omar_right = omar_max_val;
        int omar_best_ans = 1;
        
        while (omar_left <= omar_right) {
            int omar_mid = omar_left + (omar_right - omar_left) / 2;
            
            if (check_omar_target(omar_mid, n, omar_a, omar_b)) {
                omar_best_ans = omar_mid;
                omar_left = omar_mid + 1; 
            } else {
                omar_right = omar_mid - 1; 
            }
        }
        
        cout << omar_best_ans << "\n";
    }

    void omar_run() {
        int t;
        if (cin >> t) {
            while (t--) {
                execute_omar_solve();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    omar_exclusive::omar_run();
    
    return 0;
}