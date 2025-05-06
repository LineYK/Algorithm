/*
zmija
 
시간 제한 메모리 제한
1초 32MB

문제
미르코는 인기 컴퓨터 게임인 "스네이크"의 복제품을 만들고 있습니다. 이 게임에서는 R - S 픽셀 크기의 화면에서 뱀의 움직임을 제어합니다. 게임의 목적은 모든 사과를 모으는 것입니다.

안타깝게도 Mirko의 구현은 그다지 훌륭하지 않으며 게임 플레이가 원작과 다릅니다. 다음은 Mirko의 게임에 대한 설명입니다:

원작과 달리 사과가 화면에 무작위로 나타나는 것이 아니라 게임 시작 시 모든 사과의 위치를 알고 있습니다
게임 시작 시 뱀은 화면 왼쪽 아래 픽셀에 있으며 오른쪽을 향하고 있습니다
게임에는 A와 B로 표시된 두 개의 버튼이 있습니다
A 버튼을 누르면 뱀이 현재 향하고 있는 방향으로 1픽셀 앞으로 이동합니다. 이 움직임으로 인해 뱀이 화면 밖으로 나가면 아무 일도 일어나지 않습니다.
버튼 B를 누르면 뱀이 1픽셀 위로 이동하고 마주보고 있는 방향을 180° 바꿉니다
뱀이 사과가 있는 픽셀로 이동하면 사과를 먹지만 원래 게임처럼 자라지 않습니다
다음 과제가 있습니다: 게임 시작 시 주어진 사과 위치에 대해 뱀이 모든 사과를 모으는 데 필요한 가장 작은 버튼 누르는 횟수를 구하십시오.

입력
첫 번째 입력 줄에는 화면의 높이와 너비인 정수 R과 S(2 ≤ R, S ≤ 1,000)가 들어 있습니다.

다음 R 행에는 각각 정확히 S 문자가 포함됩니다. 이 문자는 화면의 콘텐츠를 나타냅니다. 사과가 있는 픽셀은 ‘J'로 표시되고 빈 픽셀은 ’.'로 표시됩니다.

왼쪽 하단에는 뱀의 초기 위치를 나타내는 ‘Z’ 문자가 포함되어 있습니다.

출력
출력의 첫 번째 줄과 유일한 줄에는 필요한 최소 버튼 누름 횟수가 포함되어야 합니다.

예제 입력 1 
5 5
...j.
.....
J..J.
J....
Z....
예제 출력 1 
7
예제 입력 2 
5 5
.....
j...j
.j.j.
.jjj.
Z....
예제 출력 2 
15
예제 입력 3 
3 4
...j
....
Z...
예제 출력 3 
5
힌트
첫 번째 예제에 대한 설명입니다: 뱀이 모든 사과를 모으는 데 필요한 가장 짧은 버튼 누르기 시퀀스는 BBAAABB입니다.
*/

#include <bits/stdc++.h>
using namespace std;
static const long long INF = (1LL<<60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, S;
    cin >> R >> S;
    vector<string> A(R);
    for(int i=0;i<R;i++) cin >> A[i];

    int H = 0;
    vector<int> L(R+1, S-1), Rv(R+1, -1);
    for(int i=0;i<R;i++){
        int row = R - i;  
        for(int c=0;c<S;c++){
            if(A[i][c]=='J'){
                L[row] = min(L[row], c);
                Rv[row] = max(Rv[row], c);
                H = max(H, row);
            }
        }
    }
    if(H==0){
        cout << 0 << "\n";
        return 0;
    }


    vector<long long> dp_prev(S, INF), dp_curr(S, INF);
    dp_prev[0] = 0;  // 시작열 = 0

    for(int i=1; i<=H; i++){
        bool right = (i & 1);

        if(right){
            vector<long long> pref(S);
            pref[0] = dp_prev[0] - 0;
            for(int p=1; p<S; p++){
                pref[p] = min(pref[p-1], dp_prev[p] - p);
            }
            for(int q=0; q<S; q++){
                if(q < Rv[i]){
                    dp_curr[q] = INF;
                } else {
                    int m = min(L[i], q);
                    dp_curr[q] = pref[m] + q;
                }
            }
        } else {
            vector<long long> suff(S);
            suff[S-1] = dp_prev[S-1] + (S-1);
            for(int p=S-2; p>=0; p--){
                suff[p] = min(suff[p+1], dp_prev[p] + p);
            }
            for(int q=0; q<S; q++){
                if(q > L[i]){
                    dp_curr[q] = INF;
                } else {
                    int k = max(Rv[i], q);
                    dp_curr[q] = suff[k] - q;
                }
            }
        }
        swap(dp_prev, dp_curr);
    }

    long long bestA = *min_element(dp_prev.begin(), dp_prev.end());
    long long answer = bestA + (H - 1);
    cout << answer << "\n";
    return 0;
}