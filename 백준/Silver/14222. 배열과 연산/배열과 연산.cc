#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> adj; // adj[i] = A[i]에서 연결된 목표 값 t들의 리스트
vector<int> matchR;     // matchR[t] = 매칭된 왼쪽 정점 i (없으면 -1)
vector<bool> seen;

bool dfs(int u) {
    for (int t : adj[u]) {
        if (seen[t]) continue;
        seen[t] = true;
        // t가 비어있거나, t에 매칭된 왼쪽 정점 i'를 다른 곳으로 보낼 수 있으면
        if (matchR[t] < 0 || dfs(matchR[t])) {
            matchR[t] = u;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // 1) 인접 리스트 구성
    adj.assign(N, {});
    for(int i = 0; i < N; i++){
        // t는 1..N
        // A[i] + m*K = t  이므로
        // t ≡ A[i] (mod K), t >= A[i], t <= N
        // 첫 t0 = A[i] + ceil((1*A[i])/K)*K  보다는 단순히:
        for(int t = A[i]; t <= N; t += K){
            if ((t - A[i]) % K == 0) {
                // 물론 t>=A[i]이므로 자동 만족
                adj[i].push_back(t);
            }
        }
    }

    // 2) 매칭 초기화
    matchR.assign(N+1, -1); // 1..N 사용
    int cnt = 0;
    // 왼쪽의 각 정점에 대해 매칭 시도
    for(int u = 0; u < N; u++){
        seen.assign(N+1, false);
        if (dfs(u)) cnt++;
    }

    // 3) 결과 출력
    // 완전 매칭(N개)이면 1, 아니면 0
    cout << (cnt == N ? 1 : 0) << "\n";
    return 0;
}