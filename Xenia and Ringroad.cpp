#include <iostream>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    long long total_time = 0; 
    int current_house = 1;   

    for (int i = 0; i < m; ++i) {
        int target;
        cin >> target;

        if (target >= current_house) {
            total_time += (target - current_house);
        } else {
            total_time += (n - current_house + target);
        }
        
        current_house = target;
    }

    cout << total_time << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}