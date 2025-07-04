#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> name(N);
    for(int i = 0; i < N; i++){
        cin >> name[i];
    }

    int R;
    cin >> R;

    // alive[i] = 아직 게임에 남아 있는 플레이어(i)
    vector<bool> alive(N, true);
    // seating: 현재 좌석 1..size 에 앉은 사람들의 원래 인덱스
    vector<int> seating(N);
    iota(seating.begin(), seating.end(), 0);

    for(int round = 0; round < R; round++){
        int S, M;
        cin >> S >> M;
        int sz = seating.size();

        // 1) 플레이어들이 시계방향으로 M칸 이동 → 시계방향으로 오른쪽으로 M칸 회전
        int shift = M % sz;
        if(shift){
            // 오른쪽으로 shift 칸 회전
            rotate(seating.begin(), seating.end() - shift, seating.end());
        }

        // 2) S번 좌석에 앉아 있던 사람이 탈락
        //    (좌석 번호는 1-based)
        int elimPos = S - 1;
        int elimPlayer = seating[elimPos];
        cout << name[elimPlayer] << " has been eliminated.\n";
        alive[elimPlayer] = false;

        // 3) 그 사람을 seating 에서 제거 → 빈 의자도 없어진다
        seating.erase(seating.begin() + elimPos);
    }

    // R라운드 후 남은 사람 수
    vector<int> survivors;
    for(int i = 0; i < N; i++){
        if(alive[i]) survivors.push_back(i);
    }

    if(survivors.size() == 1){
        cout << name[survivors[0]] << " has won.\n";
    } else {
        cout << "Players left are";
        for(int idx: survivors){
            cout << " " << name[idx];
        }
        cout << ".\n";
    }

    return 0;
}