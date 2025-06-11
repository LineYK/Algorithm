#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<vector<long long>> A(N, vector<long long>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }

    vector<long long> sum(N, 0);
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N; i++){
            sum[i] += A[i][j];
            if(sum[i] >= K){
                // 사람 번호는 1-based, 뻗은 횟수도 1-based
                cout << (i+1) << " " << (j+1) << "\n";
                return 0;
            }
        }
    }
    return 0;
}