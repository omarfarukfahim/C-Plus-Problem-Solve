#include <iostream>
#include <string>

using namespace std;

namespace byteforge_omar_hard {

    class OmarHardSeating {
    public:
        static void solve_optimal_case() {
            int omar_n, omar_x;
            long long omar_s; 
            
            if (!(cin >> omar_n >> omar_x >> omar_s)) return;
            
            string omar_friends;
            cin >> omar_friends;

            long long omar_empty_tables = omar_x;
            long long omar_e_seats = 0;  
            long long omar_a_joined = 0; 
            long long omar_seated = 0;   

            for (char personality : omar_friends) {
                if (personality == 'I') {
                    if (omar_empty_tables > 0) {
                        omar_empty_tables--;
                        omar_e_seats += (omar_s - 1);
                        omar_seated++;
                    }
                } 
                else if (personality == 'E') {
                    if (omar_e_seats > 0) {
                        omar_e_seats--;
                        omar_seated++;
                    } 
                    else if (omar_empty_tables > 0 && omar_a_joined > 0) {
                        omar_empty_tables--;
                        omar_a_joined--;
                        omar_e_seats += omar_s; 
                        
                        omar_e_seats--;
                        omar_seated++;
                    }
                } 
                else if (personality == 'A') {
                    if (omar_e_seats > 0) {
                        omar_e_seats--;
                        omar_a_joined++;
                        omar_seated++;
                    } 
                    else if (omar_empty_tables > 0) {
                        omar_empty_tables--;
                        omar_e_seats += (omar_s - 1);
                        omar_seated++;
                    }
                }
            }

            cout << omar_seated << "\n";
        }
    };

    void execute_run() {
        int omar_test_cases;
        if (cin >> omar_test_cases) {
            while (omar_test_cases--) {
                OmarHardSeating::solve_optimal_case();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    byteforge_omar_hard::execute_run();

    return 0;
}