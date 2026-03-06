#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> nums(4);
    
    if (!(cin >> nums[0] >> nums[1] >> nums[2] >> nums[3])) return;

    sort(nums.begin(), nums.end());

    int a = nums[3] - nums[0];
    int b = nums[3] - nums[1];
    int c = nums[3] - nums[2];

    cout << a << " " << b << " " << c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}