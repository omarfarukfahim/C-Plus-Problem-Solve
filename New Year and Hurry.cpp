#include <iostream>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    int available_time = 240 - k;
    int solved_count = 0;

    for (int i = 1; i <= n; ++i) {
        int time_required = 5 * i;
        
        if (available_time >= time_required) {
            available_time -= time_required; 
            solved_count++;                  
        } else {
            break;
        }
    }

    cout << solved_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}