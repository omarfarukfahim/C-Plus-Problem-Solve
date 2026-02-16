#include <iostream>
#include <string>
#include <map>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    map<string, int> db;
    string s;

    while (n--) {
        cin >> s;
        
        if (db.count(s) == 0) {
            cout << "OK" << "\n";
            db[s] = 1;
        } 
        else {
            cout << s << db[s] << "\n";
            db[s]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}