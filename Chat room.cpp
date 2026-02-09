#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    string target = "hello";
    int j = 0; 

    for (char c : s) {
        if (c == target[j]) {
            j++; 
        }
        
        if (j == 5) {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}