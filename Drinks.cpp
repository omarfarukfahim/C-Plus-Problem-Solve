#include <iostream>
#include <iomanip> 

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        sum += p;
    }

    double result = sum / n;

    cout << fixed << setprecision(12) << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}