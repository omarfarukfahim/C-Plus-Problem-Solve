/**
 * Problem: C. Registration System
 * Analysis:
 * We need to track the frequency of each username request.
 * We can use a map to store the 'next available suffix' for every name.
 * - If a name 's' is not in the map, print "OK" and set map[s] = 1.
 * - If 's' is in the map, print 's' + map[s], and then increment map[s].
 * This approach effectively assigns s1, s2, s3... to subsequent duplicates.
 */

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
        
        // If the name is not in our database
        if (db.count(s) == 0) {
            cout << "OK" << "\n";
            // Initialize the counter for this name to 1
            // (meaning the next duplicate will be name1)
            db[s] = 1;
        } 
        else {
            // Name exists, generate a new one using the stored counter
            cout << s << db[s] << "\n";
            // Increment the counter for the next time this name is requested
            db[s]++;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}