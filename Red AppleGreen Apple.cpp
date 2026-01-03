#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdint>
using namespace std;
#define MOD 998244353
#define int long long

// Function to calculate power with modulo using binary exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int32_t main() {
    // Input handling
    int N;
    cin >> N;
    vector<int> red(N), green(N);

    // Reading the red apple weights
    for (int i = 0; i < N; i++) {
        cin >> red[i];
    }

    // Reading the green apple weights
    for (int i = 0; i < N; i++) {
        cin >> green[i];
    }

    // Compute total weights
    int totalWeightRed = accumulate(red.begin(), red.end(), 0LL);
    int totalWeightGreen = accumulate(green.begin(), green.end(), 0LL);

    // Compute overall total weight
    int totalWeight = totalWeightRed + totalWeightGreen;

    vector<int> result(N);

    for (int K = 1; K <= N; K++) {
        // Compute P and Q
        int P = (totalWeight * K) % MOD;
        int Q = (N * 2) % MOD;

        // Compute Q^-1 using modular exponentiation
        int QInv = modExp(Q, MOD - 2, MOD);

        // Compute final result for K = i
        result[K - 1] = (P * QInv) % MOD;
    }

    // Output the results
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

