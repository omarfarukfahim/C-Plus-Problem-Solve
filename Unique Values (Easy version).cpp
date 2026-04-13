#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

namespace omar_namespace {

    int total_n_omar;

    int omar_query(const vector<int>& A) {
        if (A.empty()) return 0;
        
        cout << "? " << A.size();
        for (int x : A) {
            cout << " " << x;
        }
        cout << "\n";
        cout.flush();
        
        int ans;
        cin >> ans;
        if (ans == -1) {
            exit(0); 
        }
        return ans;
    }

    int omar_get_targets(const vector<int>& A) {
        if (A.empty()) return 0;
        if (A.size() == 2 * total_n_omar + 1) return 3;
        
        int qA;
        if (A.size() == 1) {
            qA = 1;
        } else {
            qA = omar_query(A);
        }
        
        vector<int> Ac;
        vector<bool> inA(2 * total_n_omar + 2, false);
        for (int x : A) inA[x] = true;
        for (int i = 1; i <= 2 * total_n_omar + 1; ++i) {
            if (!inA[i]) Ac.push_back(i);
        }
        
        int qAc;
        if (Ac.size() == 1) {
            qAc = 1;
        } else {
            qAc = omar_query(Ac);
        }
        
        int diff = qA - qAc;
        if (diff == 1) return 1;
        if (diff == -1) return 2;
        
        int parity = (A.size() - qA) % 2;
        if (parity != 0) return 3;
        
        return 0;
    }

    vector<int> omar_solve(vector<int> S, int T_S) {
        if (S.size() == (size_t)T_S) {
            return S;
        }
        if (T_S == 0) {
            return {};
        }
        
        int mid = S.size() / 2;
        vector<int> S1(S.begin(), S.begin() + mid);
        vector<int> S2(S.begin() + mid, S.end());
        
        int t1 = omar_get_targets(S1);
        int t2 = T_S - t1; 
        
        vector<int> ans;
        if (t1 > 0) {
            vector<int> res1 = omar_solve(S1, t1);
            ans.insert(ans.end(), res1.begin(), res1.end());
        }
        if (t2 > 0) {
            vector<int> res2 = omar_solve(S2, t2);
            ans.insert(ans.end(), res2.begin(), res2.end());
        }
        return ans;
    }

    void omar_run() {
        int t;
        if (!(cin >> t)) return;
        
        while (t--) {
            cin >> total_n_omar;
            
            vector<int> initial_S;
            for (int i = 1; i <= 2 * total_n_omar + 1; ++i) {
                initial_S.push_back(i);
            }
            
            vector<int> result = omar_solve(initial_S, 3);
            
            cout << "!";
            for (int x : result) {
                cout << " " << x;
            }
            cout << "\n";
            cout.flush();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    omar_namespace::omar_run();
    
    return 0;
}