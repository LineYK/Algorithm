#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N;
        cin >> N;
        int M = N * N;
        vector<vector<int>> A(M, vector<int>(M));
        for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                cin >> A[i][j];
            }
        }

        bool valid = true;
        vector<bool> seen(M+1);

        for(int i = 0; i < M && valid; i++){
            fill(seen.begin(), seen.end(), false);
            for(int j = 0; j < M; j++){
                int v = A[i][j];
                if(v < 1 || v > M || seen[v]){
                    valid = false;
                    break;
                }
                seen[v] = true;
            }
        }

        for(int j = 0; j < M && valid; j++){
            fill(seen.begin(), seen.end(), false);
            for(int i = 0; i < M; i++){
                int v = A[i][j];
                if(v < 1 || v > M || seen[v]){
                    valid = false;
                    break;
                }
                seen[v] = true;
            }
        }

        for(int bi = 0; bi < N && valid; bi++){
            for(int bj = 0; bj < N && valid; bj++){
                fill(seen.begin(), seen.end(), false);
                int r0 = bi * N;
                int c0 = bj * N;
                for(int dr = 0; dr < N; dr++){
                    for(int dc = 0; dc < N; dc++){
                        int v = A[r0+dr][c0+dc];
                        if(v < 1 || v > M || seen[v]){
                            valid = false;
                            break;
                        }
                        seen[v] = true;
                    }
                    if(!valid) break;
                }
            }
        }

        cout << "Case #" << tc << ": " << (valid ? "Yes" : "No") << "\n";
    }

    return 0;
}
