#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void solve() {
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];

    sort(nums.begin(), nums.end());

    cout << nums[1] << "\n";
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