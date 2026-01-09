#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int g, c, l;
    if (!(cin >> g >> c >> l)) return;

    // Put scores in a vector for easy sorting and min/max finding
    vector<int> scores = {g, c, l};
    sort(scores.begin(), scores.end());

    // scores[0] is min, scores[2] is max after sorting
    int diff = scores[2] - scores[0];

    if (diff >= 10) {
        cout << "check again" << endl;
    } else {
        // The median of 3 sorted numbers is the middle one (index 1)
        cout << "final " << scores[1] << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement says "A single line contains...", implying one test case per run.
    // However, standard competitive programming templates often handle multiple cases.
    // Based strictly on the input description "A single line contains three integers...", 
    // there is likely no 't' variable for number of test cases.
    solve();

    return 0;
}