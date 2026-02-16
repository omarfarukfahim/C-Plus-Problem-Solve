#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int total_faces = 0;
    string s;

    while (n--) {
        cin >> s;
        
        if (s[0] == 'T') {         
            total_faces += 4;
        } else if (s[0] == 'C') {  
            total_faces += 6;
        } else if (s[0] == 'O') {  
            total_faces += 8;
        } else if (s[0] == 'D') {  
            total_faces += 12;
        } else if (s[0] == 'I') { 
            total_faces += 20;
        }
    }

    cout << total_faces << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}