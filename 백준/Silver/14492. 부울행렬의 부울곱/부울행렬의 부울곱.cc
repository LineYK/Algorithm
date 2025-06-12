#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector< bitset<300> > A(N), Bcol(N);

    // A 행렬 읽기
    for(int i = 0; i < N; i++){
        for(int j = 0, x; j < N; j++){
            cin >> x;
            if(x) A[i].set(j);
        }
    }
    // B 행렬을 바로 "열 단위"로 저장
    // Bcol[j][k] = B[k][j]
    for(int i = 0; i < N; i++){
        for(int j = 0, x; j < N; j++){
            cin >> x;
            if(x) Bcol[j].set(i);
        }
    }

    long long cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if( (A[i] & Bcol[j]).any() ) 
                cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}