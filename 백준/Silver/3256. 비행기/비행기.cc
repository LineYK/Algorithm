#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if(!(cin >> N)) return 0;
    vector<int> R(N+1);
    int maxR = 1;
    for(int i=1;i<=N;i++){
        cin >> R[i];
        maxR = max(maxR, R[i]);
    }
    
    vector<int> pos(maxR+1, 0);       
    vector<int> stow(maxR+1, 0);     
    
    int nextPassenger = 1;   // 다음 입장하려는 승객 인덱스
    int seated = 0;          // 앉은 승객 수
    long long time = 0;

    while(seated < N){
        // 1) movement: from back to front (maxR -> 2), 사람이 r-1에 있고 r이 비어있고 그 사람이 stowing 중이 아니면 한 칸 전진
        for(int r = maxR; r >= 2; --r){
            if(pos[r] == 0 && pos[r-1] != 0 && stow[r-1] == 0){
                pos[r] = pos[r-1];
                pos[r-1] = 0;
              }
            }

        // 2) entry: 입구에서 row1로 들어오기 시도
        if(nextPassenger <= N && pos[1] == 0){
            pos[1] = nextPassenger;
            nextPassenger++;
            
        }

        // 3) start stow: 도착한 사람이 자신의 행이면 stow 시작 (단, 이미 stowing 중이면 건너뜀)
        for(int r=1; r<=maxR; ++r){
            if(pos[r] != 0){
                int p = pos[r];
                if(r == R[p] && stow[r] == 0){
                    stow[r] = 5; // 도착한 순간부터 5초 소비 (현재 초 포함)
                }
            }
        }

        // 4) 한 초 동안 stow 시간 감소, 0이 되면 비우고 seated++
        for(int r=1; r<=maxR; ++r){
            if(pos[r] != 0 && stow[r] > 0){
                stow[r]--;
                if(stow[r] == 0){
                    // 이 승객은 통로에서 사라지고 착석함
                    pos[r] = 0;
                    seated++;
                }
            }
        }

        time++;
    }

    cout << time << '\n';
    return 0;
}