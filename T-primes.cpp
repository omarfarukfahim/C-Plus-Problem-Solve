#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_SQRT = 1000000;
bool is_prime[MAX_SQRT + 5];

void sieve() {
    for (int i = 0; i <= MAX_SQRT; i++) {
        is_prime[i] = true;
    }
    
    is_prime[0] = false;
    is_prime[1] = false;
    
    for (long long p = 2; p * p <= MAX_SQRT; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= MAX_SQRT; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        if (x == 1) {
            cout << "NO\n";
            continue;
        }

        long long root = round(sqrt(x));

        if (root * root == x && is_prime[root]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    solve();

    return 0;
}