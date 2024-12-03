/*
충돌의 수
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	512 MB	300	167	157	65.417%
문제
길이가 
$L$인 상자가 있다. 이 안에 크기를 무시할 수 있을 만큼 작은 공 
$N$개가 존재한다. 길이가 
$L$인 상자는 길이가 
$1$인 구간 
$L$개로 분할할 수 있으며, 모든 공은 구간과 구간 사이의 경계에서 운동을 시작한다. 모든 공들은 
$1$초에 한 칸씩 움직인다. 만약 어떤 공이 벽이나 다른 공에 충돌한다면, 즉시 운동 방향이 반대로 바뀐다. 이때 공의 속력은 바뀌지 않는다. 또한 처음에 임의의 두 공 사이 간격은 짝수이고, 한 위치엔 하나의 공만 존재한다.



예를 들어, 위 그림은 
$L=8$일 때를 나타낸 것이다. 시간 
$t=0$일 때 빨간색 공은 처음 위치 
$1$에서 오른쪽으로 이동하고 있고, 파란 공은 처음 위치 
$5$에서 왼쪽으로 운동하고 있다. 
$t=2$일 때 두 공은 충돌하여 즉시 운동 방향이 반대로 바뀌게 된다.

 
$N$개의 공들의 처음 위치와 처음 운동 방향이 주어질 때, 시간 
$T$초까지 공끼리 몇 번 충돌하는지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 세 정수 상자의 길이 
$L$, 공의 개수 
$N$, 시간 
$T$가 공백으로 구분되어 주어진다. 
$(5 \le L \le 1\,000,\ 2 \le N \le 100,\  1 \le T \le 1\,000)$ 

두 번째 줄부터 
$N$개 줄의 
$i$번째 줄에는 
$i$번째 공의 위치를 의미하는 정수 
$S_i$와 방향 
$C_i$가 공백으로 구분되어 주어진다. 
$(1 \le S_i < L,\ C_i \in \{\texttt{L}, \texttt{R}\})$ 

여기서 공의 위치란, 상자의 왼쪽으로부터 공까지의 거리이다.

출력
공들이 서로 충돌하는 횟수를 출력한다. 
$T$초일 때 공이 서로 충돌하는 경우도 포함하여 센다.

예제 입력 1 
8 2 5
1 R
5 L
예제 출력 1 
1
예제 입력 2 
8 2 18
1 R
5 L
예제 출력 2 
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, N, T;
    cin >> L >> N >> T;

    vector<pair<int, char>> balls(N);

    for (int i = 0; i < N; i++) {
        cin >> balls[i].first >> balls[i].second;
    }

    int cnt = 0;

    for (int t = 0; t < T; t++) {
        vector<int> pos(L + 1, -1);

        for (int i = 0; i < N; i++) {
            if (balls[i].second == 'R') {
                balls[i].first++;
            } else {
                balls[i].first--;
            }

            if (balls[i].first == 0 || balls[i].first == L) {
                balls[i].second = balls[i].second == 'R' ? 'L' : 'R';
            }

            if (pos[balls[i].first] != -1) {
                cnt++;
                pos[balls[i].first] = -1;
            } else {
                pos[balls[i].first] = i;
            }
        }
    }

    cout << cnt;

	return 0;
}