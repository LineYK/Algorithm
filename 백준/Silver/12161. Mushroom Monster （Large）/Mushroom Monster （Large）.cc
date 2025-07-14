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
        vector<long long> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }

        
        long long y = 0;
        for(int i = 0; i + 1 < N; i++){
            if(A[i] > A[i+1])
                y += (A[i] - A[i+1]);
        }

      
        long long R = 0;
        for(int i = 0; i + 1 < N; i++){
            R = max(R, A[i] - A[i+1]);
        }
        long long z = 0;
        for(int i = 0; i + 1 < N; i++){
            z += min(A[i], R);
        }

        cout << "Case #" << tc << ": " << y << " " << z;
        if(tc < T) cout << "\n";
    }
    return 0;
}