#include <iostream>
#include <string>
#include <set>
#include <cctype> 

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    string s;
    cin >> s;

    if (n < 26) {
        cout << "NO" << "\n";
        return;
    }

    set<char> distinct_letters;

    for (char c : s) {
        if (isalpha(c)) { 
            distinct_letters.insert(tolower(c));
        }
    }

    if (distinct_letters.size() == 26) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}