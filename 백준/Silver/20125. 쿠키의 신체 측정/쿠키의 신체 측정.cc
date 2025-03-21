/*
쿠키의 신체 측정
 
시간 제한	메모리 제한
1 초	1024 MB	

문제
쿠키런은 데브시스터즈에서 제작한 모바일 러닝 액션 게임이다. 마녀의 오븐에서 탈출한 쿠키들과 함께 모험을 떠나는 게임으로, 점프와 슬라이드 2가지 버튼만으로 손쉽게 플레이할 수 있는 것이 특징이다.

연세대학교를 졸업한 김강산 선배님이 데브시스터즈에 취직하면서 주변 사람들에게 쿠키런을 전파시켰다. 하지만 게임을 전파하던 중에 쿠키들에게 신체적으로 이상이 생기는 것을 발견하였다. 팔, 다리 길이가 임의적으로 변한 것이다. 때문에 긴급하게 각 쿠키들의 신체들을 측정하려고 한다.

쿠키들은 신체를 측정하기 위해서 한 변의 길이가 N인 정사각형 판 위에 누워있으며, 어느 신체 부위도 판 밖으로 벗어나지 않는다. 판의 x번째 행, y번째 열에 위치한 곳을 (x, y)로 지칭한다. 판의 맨 왼쪽 위 칸을 (1, 1), 오른쪽 아래 칸을 (N, N)으로 나타낼 수 있다.



그림과 같이 쿠키의 신체는 머리, 심장, 허리, 그리고 좌우 팔, 다리로 구성되어 있다. 그림에서 빨간 곳으로 칠해진 부분이 심장이다. 머리는 심장 바로 윗 칸에 1칸 크기로 있다. 왼쪽 팔은 심장 바로 왼쪽에 붙어있고 왼쪽으로 뻗어 있으며, 오른쪽 팔은 심장 바로 오른쪽에 붙어있고 오른쪽으로 뻗어있다. 허리는 심장의 바로 아래 쪽에 붙어있고 아래 쪽으로 뻗어 있다. 왼쪽 다리는 허리의 왼쪽 아래에, 오른쪽 다리는 허리의 오른쪽 아래에 바로 붙어있고, 각 다리들은 전부 아래쪽으로 뻗어 있다. 각 신체 부위들은 절대로 끊겨있지 않으며 굽혀진 곳도 없다. 또한, 허리, 팔, 다리의 길이는 1 이상이며, 너비는 무조건 1이다.

쿠키의 신체가 주어졌을 때 심장의 위치와 팔, 다리, 허리의 길이를 구하여라.

입력
다음과 같이 입력이 주어진다.

N
a1,1 . . . a1,N
. . . . . .
aN,1 . . . aN,N
출력
첫 번째 줄에는 심장이 위치한 행의 번호 x와 열의 번호 y를 공백으로 구분해서 출력한다.

두 번째 줄에는 각각 왼쪽 팔, 오른쪽 팔, 허리, 왼쪽 다리, 오른쪽 다리의 길이를 공백으로 구분해서 출력하여라.

제한
5 ≤ N ≤ 1,000. N은 판의 한 변의 길이를 의미하는 양의 정수다.
ai,j는 * 또는 _이다. *는 쿠키의 신체 부분이고, _는 쿠키의 신체가 올라가 있지 않은 칸을 의미한다. (1 ≤ i, j ≤ N)
쿠키의 신체 조건에 위배되는 입력은 주어지지 않는다.
예제 입력 1 
5
_____
__*__
_***_
__*__
_*_*_
예제 출력 1 
3 3
1 1 1 1 1
예제 입력 2 
10
__________
_____*____
__******__
_____*____
_____*____
_____*____
____*_*___
____*_____
____*_____
____*_____
예제 출력 2 
3 6
3 2 3 4 1
예제 입력 3 
9
____*____
*********
____*____
____*____
____*____
___*_*___
___*_*___
___*_*___
___*_*___
예제 출력 3 
2 5
4 4 3 4 4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<string> board(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> board[i];
        board[i] = "_" + board[i]; 
    }
    
    int heart_x = 0, heart_y = 0;
    for (int i = 2; i < N; i++) {
        for (int j = 2; j < N; j++) {
            if (board[i][j] == '*') {
                if (board[i-1][j] == '*' && board[i+1][j] == '*' && 
                    board[i][j-1] == '*' && board[i][j+1] == '*') {
                    heart_x = i;
                    heart_y = j;
                    break;
                }
            }
        }
        if (heart_x != 0) break;
    }
    
    int left_arm = 0;
    for (int j = heart_y - 1; j >= 1; j--) {
        if (board[heart_x][j] == '*') left_arm++;
        else break;
    }
    
    int right_arm = 0;
    for (int j = heart_y + 1; j <= N; j++) {
        if (board[heart_x][j] == '*') right_arm++;
        else break;
    }
    
    int waist = 0;
    for (int i = heart_x + 1; i <= N; i++) {
        if (board[i][heart_y] == '*') waist++;
        else break;
    }
    
    int waist_end_x = heart_x + waist;
    
    int left_leg = 0;
    for (int i = waist_end_x + 1; i <= N; i++) {
        if (board[i][heart_y - 1] == '*') left_leg++;
        else break;
    }
    
    int right_leg = 0;
    for (int i = waist_end_x + 1; i <= N; i++) {
        if (board[i][heart_y + 1] == '*') right_leg++;
        else break;
    }
    
    cout << heart_x << " " << heart_y << "\n";
    cout << left_arm << " " << right_arm << " " << waist << " " << left_leg << " " << right_leg << "\n";
    
    return 0;
}