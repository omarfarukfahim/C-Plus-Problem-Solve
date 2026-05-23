#include <iostream>
#include <algorithm>

using namespace std;

namespace byteforge_omar {

    class TechWizardSolver {
    public:
        static void solve_slime_case() {
            int n_slimes;
            cin >> n_slimes;

            int omar_min = 1000000000;
            int omar_max = -1000000000;

            for (int i = 0; i < n_slimes; ++i) {
                int pos;
                cin >> pos;
                omar_min = min(omar_min, pos);
                omar_max = max(omar_max, pos);
            }

            
            int omar_moves = (omar_max - omar_min + 1) / 2;
            
            cout << omar_moves << "\n";
        }
    };

    void execute_run() {
        int test_cases;
        if (cin >> test_cases) {
            while (test_cases--) {
                TechWizardSolver::solve_slime_case();
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