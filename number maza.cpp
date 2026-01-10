#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string n;
    int j, k;
    if (!(cin >> n >> j >> k)) return;

    sort(n.begin(), n.end());
    
    vector<string> perms;
    do {
        perms.push_back(n);
    } while (next_permutation(n.begin(), n.end()));
    
    string s1 = perms[j - 1];
    string s2 = perms[k - 1];
    
    int A = 0;
    int len = s1.length();
    
    for (int i = 0; i < len; ++i) {
        if (s1[i] == s2[i]) {
            A++;
        }
    }
    
    int B = len - A;
    
    cout << A << "A" << B << "B" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}