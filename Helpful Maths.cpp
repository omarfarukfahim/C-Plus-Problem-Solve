#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    vector<int> nums;
    
    for (size_t i = 0; i < s.length(); i += 2) {
        nums.push_back(s[i] - '0');
    }

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << "+";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}