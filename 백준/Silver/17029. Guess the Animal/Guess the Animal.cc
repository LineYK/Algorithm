#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<unordered_set<string>> C(N);

    for(int i = 0; i < N; i++){
        string name;
        int K;
        cin >> name >> K;
        C[i].reserve(K*2);
        for(int j = 0; j < K; j++){
            string s;
            cin >> s;
            C[i].insert(s);
        }
    }

    int best = 0;
    // 모든 동물 쌍에 대해 공통 특징의 개수 계산
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int cnt = 0;
            // 작은 쪽을 순회하면서 교집합 개수 세기
            if(C[i].size() < C[j].size()){
                for(auto &x : C[i]){
                    if(C[j].count(x)) cnt++;
                }
            } else {
                for(auto &x : C[j]){
                    if(C[i].count(x)) cnt++;
                }
            }
            best = max(best, cnt);
        }
    }

    // 최대 공통 개수 + 1 이 정답
    cout << (best + 1) << "\n";
    return 0;
}