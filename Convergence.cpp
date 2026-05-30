#include <iostream>
#include <vector>

using namespace std;

namespace byteforge_omar {

    class ConvergenceSolver {
    public:
        static void solve_omar_case() {
            int omar_friends_count;
            cin >> omar_friends_count;

            for (int i = 0; i < omar_friends_count; ++i) {
                long long coordinate;
                cin >> coordinate;
            }

            int minimum_calls = omar_friends_count / 2;

            cout << minimum_calls << "\n";
        }
    };

    void run_exclusive_engine() {
        int omar_test_cases;
        if (cin >> omar_test_cases) {
            while (omar_test_cases--) {
                ConvergenceSolver::solve_omar_case();
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