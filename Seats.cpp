#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> ones_indices;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones_indices.push_back(i);
        }
    }

    if (ones_indices.empty()) {
        cout << (n + 2) / 3 << "\n";
        return;
    }

    int added_students = 0;

    int l_gap = ones_indices[0];
    added_students += (l_gap + 1) / 3;

    for (size_t i = 0; i < ones_indices.size() - 1; ++i) {
        int gap_len = ones_indices[i+1] - ones_indices[i] - 1;
        added_students += gap_len / 3;
    }

    int r_gap = n - 1 - ones_indices.back();
    added_students += (r_gap + 1) / 3;

    cout << ones_indices.size() + added_students << "\n";
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