/*
6789
 
시간 제한 메모리 제한
1초 (추가 시간 없음) 1024MB

문제
재현이는 숫자를 좋아합니다. 10자리 숫자 중 6, 7, 8, 9를 가장 좋아합니다. 
그래서 6, 7, 8, 9로만 구성된 특별한 카드 세트를 만들었습니다. 

현재 재현이는 N x M 카드를 가지고 있습니다. 
재현은 마법의 N × M 카드 매트릭스를 만들고 싶어요. 
행렬의 각 행에는 M장의 카드가 있어야 합니다. 
재현은 이미 카드를 N×M 행렬의 모양으로 배열했습니다.
 
그림 1. 점 대칭이 아닌 초기 상태.
매직 매트릭스가 되려면 매트릭스가 점 대칭이어야 합니다: 행렬을 180도 회전하면 원래 행렬과 동일한 상태가 됩니다. 
예를 들어 8은 그 자체로 점 대칭이고, 6과 9는 서로 점 대칭입니다.

재현은 카드의 위치를 바꾸고 싶지 않으므로 
카드를 원래 위치에서 회전하는 것만으로 행렬의 점을 대칭으로 만드는 것이 목표입니다.

그림 2. 두 카드를 회전한 후, 두 카드는 점 대칭이 됩니다.
매직 매트릭스를 만들기 위해 돌려야 하는 카드의 최소 개수를 구합니다.

입력
첫 번째 줄에는 두 개의 정수인 N과 M이 들어 있습니다(1 le N, M le 500).

다음 N 줄에는 각 카드에 쓰여진 숫자를 나타내는 M 문자의 문자열이 들어 있습니다. 
각 문자는 6, 7, 8 또는 9 중 하나라는 것이 보장됩니다.

출력
첫 번째 줄에 매직 매트릭스를 만들기 위해 돌려야 하는 최소 카드 수를 인쇄합니다. 
매직 매트릭스를 만들 수 없는 경우 “-1”을 인쇄합니다(따옴표 제외).

예제 입력 1 
2 3
676
679
예제 출력 1 
2
예제 입력 2 
3 3
888
888
888
예제 출력 2 
0
예제 입력 3 
1 1
7
예제 출력 3 
-1
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

char getFace(char d, int rotated) {
    if(d == '6') return (rotated ? '9' : '6');
    if(d == '9') return (rotated ? '6' : '9');
    if(d == '8') return '8';
    if(d == '7') return (rotated ? 'A' : '7'); 
    return '?'; // 도달하면 안 됨
}

char f(char x) {
    if(x == '6') return '9';
    if(x == '9') return '6';
    if(x == '8') return '8';
    if(x == '7') return 'A';
    if(x == 'A') return '7';
    return '?';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++){
        cin >> mat[i];
    }
    
    int total_cost = 0;
    bool possible = true;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int sym_i = n - 1 - i;
            int sym_j = m - 1 - j;
            if(i > sym_i || (i == sym_i && j > sym_j)) continue;
            
            if(i == sym_i && j == sym_j){
                int best = INF;
                for (int state = 0; state < 2; state++){
                    char face = getFace(mat[i][j], state);
                    if(face == f(face)){
                        best = min(best, state); // state가 0 또는 1
                    }
                }
                if(best == INF){
                    possible = false;
                    break;
                } else {
                    total_cost += best;
                }
            } else {
                int best = INF;
                for (int state1 = 0; state1 < 2; state1++){
                    for (int state2 = 0; state2 < 2; state2++){
                        char face1 = getFace(mat[i][j], state1);
                        char face2 = getFace(mat[sym_i][sym_j], state2);
                        if(face1 == f(face2)){
                            best = min(best, state1 + state2);
                        }
                    }
                }
                if(best == INF){
                    possible = false;
                    break;
                } else {
                    total_cost += best;
                }
            }
        }
        if(!possible) break;
    }
    
    if(!possible)
        cout << -1 << "\n";
    else
        cout << total_cost << "\n";
        
    return 0;
}