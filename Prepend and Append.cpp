#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int left = 0;
    int right = n - 1;

    while (left < right && s[left] != s[right]) {
        left++;
        right--;
    }

    cout << right - left + 1 << "\n";
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