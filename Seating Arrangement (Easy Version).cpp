#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace omar_seating_system {

    class OmarTableOptimizer {
    public:
        static void execute_omar_logic() {
            int omar_n, omar_x, omar_s;
            cin >> omar_n >> omar_x >> omar_s;
            
            string omar_friends;
            cin >> omar_friends;

            vector<int> omar_state(omar_x + 1, -1);
            omar_state[0] = 0;

            for (char personality : omar_friends) {
                vector<int> next_omar_state = omar_state;

                for (int j = 0; j <= omar_x; ++j) {
                    if (omar_state[j] == -1) continue;

                    if (personality == 'I') {
                        if (j + 1 <= omar_x) {
                            next_omar_state[j + 1] = max(next_omar_state[j + 1], omar_state[j]);
                        }
                    } 
                    else if (personality == 'E') {
                        if (omar_state[j] < j * (omar_s - 1)) {
                            next_omar_state[j] = max(next_omar_state[j], omar_state[j] + 1);
                        }
                    } 
                    else if (personality == 'A') {
                        if (j + 1 <= omar_x) {
                            next_omar_state[j + 1] = max(next_omar_state[j + 1], omar_state[j]);
                        }
                        if (omar_state[j] < j * (omar_s - 1)) {
                            next_omar_state[j] = max(next_omar_state[j], omar_state[j] + 1);
                        }
                    }
                }
                omar_state = next_omar_state;
            }

            int omar_max_seated = 0;
            for (int j = 0; j <= omar_x; ++j) {
                if (omar_state[j] != -1) {
                    omar_max_seated = max(omar_max_seated, j + omar_state[j]);
                }
            }

            cout << omar_max_seated << "\n";
        }
    };

    void run_exclusive_engine() {
        int omar_test_cases;
        if (cin >> omar_test_cases) {
            while (omar_test_cases--) {
                OmarTableOptimizer::execute_omar_logic();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    omar_seating_system::run_exclusive_engine();

    return 0;
}