/**
 * Problem: A. Sereja and Dima
 * Analysis:
 * We use a two-pointer approach to simulate the game. 
 * 'left' points to the start of the remaining cards, and 'right' points to the end.
 * On each turn, the current player greedily picks the maximum of cards[left] and cards[right].
 * We update the scores and move the corresponding pointer inward until all cards are taken.
 */

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    // Read the number of cards
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

    // Simulate the game until no cards are left
    while (left <= right) {
        int picked_card;
        
        // Greedily pick the larger card from the ends
        if (cards[left] > cards[right]) {
            picked_card = cards[left];
            left++;
        } else {
            picked_card = cards[right];
            right--;
        }

        // Add the picked card to the current player's score
        if (is_sereja_turn) {
            sereja_score += picked_card;
        } else {
            dima_score += picked_card;
        }
        
        // Switch turns
        is_sereja_turn = !is_sereja_turn;
    }

    // Output Sereja's score followed by Dima's score
    cout << sereja_score << " " << dima_score << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}