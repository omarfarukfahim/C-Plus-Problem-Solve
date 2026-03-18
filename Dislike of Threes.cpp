#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_sequence() {
    vector<int> seq;
    int current_number = 1;
    
    while (seq.size() < 1000) {
        if (current_number % 3 != 0 && current_number % 10 != 3) {
            seq.push_back(current_number);
        }
        current_number++;
    }
    return seq;
}

void solve() {
    vector<int> valid_numbers = generate_sequence();

    int t;
    if (cin >> t) {
        while (t--) {
            int k;
            cin >> k;
            cout << valid_numbers[k - 1] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}