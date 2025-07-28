/*
데스 나이트
 
시간 제한   메모리 제한
2 초   512 MB

문제
게임을 좋아하는 큐브러버는 체스에서 사용할 새로운 말 "데스 나이트"를 만들었다. 데스 나이트가 있는 곳이 (r, c)라면, (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동할 수 있다.

크기가 N×N인 체스판과 두 칸 (r1, c1), (r2, c2)가 주어진다. 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 구해보자. 체스판의 행과 열은 0번부터 시작한다.

데스 나이트는 체스판 밖으로 벗어날 수 없다.

입력
첫째 줄에 체스판의 크기 N(5 ≤ N ≤ 200)이 주어진다. 둘째 줄에 r1, c1, r2, c2가 주어진다.

출력
첫째 줄에 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.

예제 입력 1 
7
6 6 0 1
예제 출력 1 
4
예제 입력 2 
6
5 1 0 5
예제 출력 2 
-1
예제 입력 3 
7
0 3 4 3
예제 출력 3 
2
*/

#include <bits/stdc++.h>
using namespace std;

const int dx[6] = {-2, -2, 0, 0, 2, 2};
const int dy[6] = {-1, 1, -2, 2, 1, -1};

bool isValid(int r, int c, int N) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int bfs(int r1, int c1, int r2, int c2, int N) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<int>> dist(N, vector<int>(N, -1));

    q.push({r1, c1});
    visited[r1][c1] = true;
    dist[r1][c1] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == r2 && c == c2) {
            return dist[r][c];
        }

        for (int i = 0; i < 6; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (isValid(nr, nc, N) && !visited[nr][nc]) {
                visited[nr][nc] = true;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return -1; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int result = bfs(r1, c1, r2, c2, N);
    cout << result << '\n';

    return 0;
}