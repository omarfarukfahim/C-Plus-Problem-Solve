#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace byteforge_omar {

    class ConvergenceSolver {
    public:
        static void execute_omar_correction() {
            int omar_n;
            cin >> omar_n;

            vector<long long> omar_positions(omar_n);
            for (int i = 0; i < omar_n; ++i) {
                cin >> omar_positions[i];
            }

            int omar_optimal_calls = 1e9; 

            for (int i = 0; i < omar_n; ++i) {
                long long omar_target = omar_positions[i];
                int left_count = 0;
                int right_count = 0;

                for (int j = 0; j < omar_n; ++j) {
                    if (omar_positions[j] < omar_target) {
                        left_count++;
                    } else if (omar_positions[j] > omar_target) {
                        right_count++;
                    }
                }

                int current_calls = max(left_count, right_count);
                
                omar_optimal_calls = min(omar_optimal_calls, current_calls);
            }

            cout << omar_optimal_calls << "\n";
        }
    };

    void run_exclusive_engine() {
        int omar_test_cases;
        if (cin >> omar_test_cases) {
            while (omar_test_cases--) {
                ConvergenceSolver::execute_omar_correction();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    byteforge_omar::run_exclusive_engine();

    return 0;
}