/*
침략자 진아
 
시간 제한   메모리 제한
2 초   256 MB   

문제
진아는 행성의 침략자이다. 진아의 행성 침략 방법은 너무 끔찍하기로 소문이 나 있다.

진아는 2개의 독주머니를 가지고 있는데, 독주머니는 빠른 속도로 독을 퍼트려 행성에 있는 생물을 중독시킨다고 한다. 독주머니의 독은 1초마다 인접한 지역으로 퍼질 정도로 빠르다! 진아는 바쁘기 때문에 아주 빠르게 행성을 침략하고자 한다.

당신은 진아의 조수이다. 진아는 포악하기 때문에 독주머니를 설치할 최적의 위치를 알려주지 않는다면 고문을 당할 수도 있다! 진아에게 최적의 위치에 설치한다면 몇 초 만에 모든 마을에 독이 퍼질 수 있을지 알려주자.

먼저 2차원 지도에 마을들의 위치가 주어진다. 예를 들어 행성의 지도가 다음과 같이 주어졌을 때,

5 6
110011
000000
000000
011010
000000
맨 위의 가장 왼쪽이 0,0 이라고 할 때 (2,1) 과 (2,4) 에 독주머니를 설치한다면 3초 만에 모든 마을이 중독된다. (2, 1)은  3번째 줄의 2번째 칸이다. (행성 전체가 중독되는데 걸리는 시간을 구하는 것이 아니라 모든 마을이 중독되는데 걸리는 시간을 묻는 것이다.) 

단, 독주머니를 마을에는 둘 수 없다. 빈 공간에만 둘 수 있다. 마을에 독주머니를 뒀다간 들킬 수도 있기 때문이다.

또한, A라는 마을과 B라는 마을이 인접해있고 A라는 마을이 중독되었다면 1초 후에 B라는 마을로 전염된다. (이 문제에서 인접이란 상하좌우를 뜻한다.)

입력
2차원 공간의 세로의 크기와 가로의 크기를 의미하는 두 정수 N, M(2 ≤ N, M ≤ 20)이 주어진다.

예제 입력과 같이 마을의 지도가 주어진다. 0은 빈 공간을, 1은 마을이 있는 공간을 의미한다.

출력
가장 최적의 위치 두 곳에 독주머니를 설치 시, 몇 초 만에 행성을 초토화 시킬 수 있는지 출력하시오.

단, 독주머니를 설치하지 못하는 경우는 없다.

예제 입력 1 
5 6
110011
000000
000000
011010
000000
예제 출력 1 
3
예제 입력 2 
19 18
001010001000011000
000000100110010100
000001000110110000
001000000000000100
000000010011000010
100101010010000100
010000110101100001
000100001001101001
101001110100100000
001000100000010000
010011101101000100
100001100110010001
010010110100000001
001001000000100000
000000000000101010
101010000001101111
011110000000000111
000000001010100000
001100010110000000
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<string> board;
vector<pair<int, int>> empty_cells;
vector<pair<int, int>> town_cells;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(pair<int, int> p1, pair<int, int> p2) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    q.push(p1); q.push(p2);
    dist[p1.first][p1.second] = 0;
    dist[p2.first][p2.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] != -1) continue;
            if (board[nx][ny] == '1' || board[nx][ny] == '0') {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int time = 0;
    for (auto [x, y] : town_cells) {
        if (dist[x][y] == -1) return INF; 
        time = max(time, dist[x][y]);
    }
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '0') empty_cells.push_back({i, j});
            if (board[i][j] == '1') town_cells.push_back({i, j});
        }
    }

    int ans = INF;
    int sz = empty_cells.size();
    for (int i = 0; i < sz; ++i) {
        for (int j = i + 1; j < sz; ++j) {
            int time = bfs(empty_cells[i], empty_cells[j]);
            ans = min(ans, time);
        }
    }

    cout << ans << '\n';
    return 0;
}