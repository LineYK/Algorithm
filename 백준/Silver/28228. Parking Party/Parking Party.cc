#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    vector<vector<bool>> l(n, vector<bool>(m, false)),
                         r(n, vector<bool>(m, false)),
                         t(n, vector<bool>(m, false)),
                         b(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        bool clear = true;
        for(int j = 0; j < m; j++){
            if (A[i][j] == 'o') clear = false;
            l[i][j] = clear;
        }
        clear = true;
        for(int j = m-1; j >= 0; j--){
            if (A[i][j] == 'o') clear = false;
            r[i][j] = clear;
        }
    }
    for(int j = 0; j < m; j++){
        bool clear = true;
        for(int i = 0; i < n; i++){
            if (A[i][j] == 'o') clear = false;
            t[i][j] = clear;
        }
        clear = true;
        for(int i = n-1; i >= 0; i--){
            if (A[i][j] == 'o') clear = false;
            b[i][j] = clear;
        }
    }

    long long answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (A[i][j]=='.' && (l[i][j]||r[i][j]||t[i][j]||b[i][j]))
                answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}
