#include <iostream>

using namespace std;

long long get_digit_sum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    long long x;
    if (!(cin >> x)) return;

    int count = 0;

    for (long long y = x + 1; y <= x + 100; ++y) {
        if (y - get_digit_sum(y) == x) {
            count++;
        }
    }

    cout << count << "\n";
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