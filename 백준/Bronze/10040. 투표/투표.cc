#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if(!(cin >> N >> M)) return 0;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++) cin >> A[i];
    vector<int> B(M);
    int maxB = 0;
    for(int j=0;j<M;j++){
        cin >> B[j];
        maxB = max(maxB, B[j]);
    }

    vector<int> first(maxB+1, 0);
    for(int t=1; t<=maxB; ++t){
        for(int i=1;i<=N;i++){
            if(A[i] <= t){
                first[t] = i;
                break;
            }
        }
    }

    vector<int> votes(N+1, 0);
    for(int j=0;j<M;j++){
        int t = B[j];
        int idx = first[t];
        votes[idx]++;
    }

    int bestIdx = 1;
    for(int i=2;i<=N;i++){
        if(votes[i] > votes[bestIdx]) bestIdx = i;
    }

    cout << bestIdx << '\n';
    return 0;
}