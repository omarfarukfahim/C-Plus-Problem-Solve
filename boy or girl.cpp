#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    set<char> distinct_chars;
    for (char c : s) {
        distinct_chars.insert(c);
    }

    if (distinct_chars.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << "\n";
    } else {
        cout << "IGNORE HIM!" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}