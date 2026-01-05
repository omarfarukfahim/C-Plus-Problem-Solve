#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s, t;
    if (!(cin >> s >> t)) return;

    // Frequency counts
    vector<int> cnt_s(26, 0), cnt_t(26, 0);
    for (char c : s) cnt_s[c - 'a']++;
    for (char c : t) cnt_t[c - 'a']++;

    // Check if s can be a subsequence of t (anagram check subset)
    for (int i = 0; i < 26; ++i) {
        if (cnt_t[i] < cnt_s[i]) {
            cout << "Impossible\n";
            return;
        }
    }

    // Construct the sorted string of remaining characters
    string rem;
    rem.reserve(t.length() - s.length());
    for (int i = 0; i < 26; ++i) {
        if (cnt_t[i] > cnt_s[i]) {
            rem.append(cnt_t[i] - cnt_s[i], (char)('a' + i));
        }
    }

    string res;
    res.reserve(t.length());
    
    int r_idx = 0;
    int r_len = rem.size();

    // Merge s and rem
    for (char c : s) {
        // Insert remaining chars ONLY if they are strictly smaller
        while (r_idx < r_len && rem[r_idx] < c) {
            res += rem[r_idx++];
        }
        res += c;
    }

    // Append any leftover remaining characters
    while (r_idx < r_len) {
        res += rem[r_idx++];
    }

    cout << res << "\n";
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