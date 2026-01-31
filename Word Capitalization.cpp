#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    s[0] = toupper(s[0]);

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}