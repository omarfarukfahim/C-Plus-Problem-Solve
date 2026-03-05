#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    int left = 0;
    int right = n - 1;
    
    int sereja_score = 0;
    int dima_score = 0;
    bool is_sereja_turn = true;

    while (left <= right) {
        int picked_card;
        
        if (cards[left] > cards[right]) {
            picked_card = cards[left];
            left++;
        } else {
            picked_card = cards[right];
            right--;
        }

        if (is_sereja_turn) {
            sereja_score += picked_card;
        } else {
            dima_score += picked_card;
        }
        
        is_sereja_turn = !is_sereja_turn;
    }

    cout << sereja_score << " " << dima_score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}