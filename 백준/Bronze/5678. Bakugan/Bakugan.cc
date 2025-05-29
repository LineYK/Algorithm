/*
바쿠간 
 
시간 제한    메모리 제한
1 초    128 MB    

문제
마크와 레티는 바쿠간 볼로 놀기를 좋아합니다. 이 볼은 작은 플라스틱 구형으로, 안쪽에 작은 괴물 장난감이 들어 있습니다. 바닥에 떨어뜨리면 바쿠간 볼이 놀라운 소리와 함께 터져 열리며, 두려운 바쿠간 괴물이 나타납니다. 마크와 레티는 장난감 몬스터로 놀기를 좋아하지만, 볼을 터뜨리는 것도 큰 재미입니다.

각각은 바쿠간 볼이 들어 있는 가방을 받았고, 볼을 터뜨리는 게임을 만들었습니다. 10가지 다른 몬스터가 있으며, 마크와 레티는 몬스터의 추악함에 따라 각 몬스터에 1부터 10까지의 다른 정수를 할당했습니다. 게임은 R 라운드로 구성됩니다. 각 라운드마다:

두 플레이어가 동시에 각자 한 개의 공을 떨어뜨립니다;  
각 플레이어는 자신의 공으로 해방된 몬스터와 연관된 숫자와 일치하는 점수를 누적합니다;  
세 번 연속으로 같은 몬스터를 해방한 첫 번째(그리고 유일한) 플레이어는 30점의 추가 점수를 얻습니다; 만약 이 조건이 같은 라운드에서 두 플레이어 모두에게 발생하면 추가 점수는 없습니다.
게임의 승자는 더 많은 점수를 획득한 플레이어입니다. 마크와 레티가 게임의 승자를 발표하도록 도와주세요!

입력
각 테스트 케이스는 세 줄로 설명됩니다. 첫 번째 줄에는 게임의 라운드 수를 나타내는 정수 R(1 ≤ R ≤ 10)이 포함됩니다. 두 번째 줄에는 마크가 각 라운드에서 해방시킨 몬스터를 나타내는 R개의 정수 Mi(1 ≤ Mi ≤ 10, 1 ≤ i ≤ R)가 포함됩니다. 세 번째 줄에는 레티가 각 라운드에서 해방시킨 몬스터를 나타내는 R개의 정수 Li(1 ≤ Li ≤ 10, 1 ≤ i ≤ R)가 포함됩니다.

마지막 테스트 케이스 뒤에는 0이 하나 포함된 행이 따라옵니다.

출력
각 테스트 케이스에 대해 게임의 결과를 나타내는 문자로 구성된 행을 출력합니다: Mark가 승리하면 대문자 ‘M’, Leti가 승리하면 대문자 ‘L’, 무승부라면 대문자 'T'를 출력합니다.

예제 입력 1 
10
4 2 2 2 5 6 7 8 1 1
1 4 4 4 1 1 1 1 2 3
5
3 3 3 3 2
8 9 9 9 9
10
8 4 7 1 1 9 5 2 4 3
5 6 9 7 9 4 2 3 7 4
0
예제 출력 1 
M
T
L
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int R;
        cin >> R;
        if (R == 0) break;

        vector<int> M(R), L(R);
        for (int i = 0; i < R; i++) cin >> M[i];
        for (int i = 0; i < R; i++) cin >> L[i];

        int markScore = 0, letiScore = 0;
        int mCnt = 0, lCnt = 0;
        bool bonusGiven = false;

        int prevM = -1, prevL = -1;
        for (int i = 0; i < R; i++) {
            markScore += M[i];
            letiScore += L[i];

            mCnt = (M[i] == prevM) ? mCnt + 1 : 1;
            lCnt = (L[i] == prevL) ? lCnt + 1 : 1;
            prevM = M[i];
            prevL = L[i];

            if (!bonusGiven) {
                if (mCnt == 3 && lCnt != 3) {
                    markScore += 30;
                    bonusGiven = true;
                }
                else if (lCnt == 3 && mCnt != 3) {
                    letiScore += 30;
                    bonusGiven = true;
                }
                else if (mCnt == 3 && lCnt == 3) {
                    bonusGiven = true;
                }
            }
        }

        if (markScore > letiScore) cout << "M\n";
        else if (letiScore > markScore) cout << "L\n";
        else cout << "T\n";
    }

    return 0;
}