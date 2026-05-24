#include <iostream>
#include <vector>

using namespace std;

namespace byteforge_omar {

    class FlippingSolver {
    public:
        static void execute_omar_logic() {
            int n;
            if (!(cin >> n)) return;

            vector<long long> omar_arr(n);
            for (int i = 0; i < n; i++) {
                cin >> omar_arr[i];
            }

            int omar_flips = 0;
            vector<int> omar_ops;

            for (int i = n - 1; i >= 0; i--) {
                long long current_val = omar_arr[i];
                
                if (omar_flips % 2 != 0) {
                    current_val = -current_val;
                }

                if (current_val > 0) {
                    omar_ops.push_back(i + 1); 
                    omar_flips++;
                }
            }

            cout << omar_ops.size() << "\n";
            for (int i = 0; i < omar_ops.size(); i++) {
                cout << omar_ops[i] << (i == omar_ops.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    };

    void execute_run() {
        int test_cases;
        if (cin >> test_cases) {
            while (test_cases--) {
                FlippingSolver::execute_omar_logic();
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