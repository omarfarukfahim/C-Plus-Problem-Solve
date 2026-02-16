#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
    string s;
    getline(cin, s);

    set<char> distinct_letters;

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            distinct_letters.insert(c);
        }
    }

    cout << distinct_letters.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}