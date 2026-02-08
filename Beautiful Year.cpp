#include <iostream>

using namespace std;

void solve() {
    int y;
    if (!(cin >> y)) return;

    while (true) {
        y++; 
        
        int a = y / 1000;       
        int b = (y / 100) % 10; 
        int c = (y / 10) % 10;  
        int d = y % 10;         

        if (a != b && a != c && a != d &&
            b != c && b != d &&
            c != d) {
            
            cout << y << "\n";
            break; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}