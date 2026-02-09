#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int groups = 0;
    string prev = ""; 
    
    for (int i = 0; i < n; ++i) {
        string curr;
        cin >> curr;

        if (i == 0) {
            groups++;
        } 
        else if (curr != prev) {
            groups++;
        }
        
        prev = curr;
    }

    cout << groups << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}