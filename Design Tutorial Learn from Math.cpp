#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (n % 2 == 0) {
            cout << 4 << " " << n - 4 << "\n";
        } 
        else {
            cout << 9 << " " << n - 9 << "\n";
        }
    }

    return 0;
}