/*
기사의 여정

시간 제한    메모리 제한
1초        128 MB
문제
직각 격자판의 크기는 n*m 칸입니다. 체스의 나이트는 격자판의 왼쪽 아래 칸(좌표 (1;1))에 위치해 있습니다(그림 1 참고).

체스의 나이트는 체스 규칙에 따라 이동할 수 있습니다. 즉, 한 번의 이동에서 수직 방향으로 한 칸, 수평 방향으로 두 칸(또는 그 반대)으로 이동할 수 있습니다.

예를 들어, n=4, m=3이고 나이트가 (2;1)에 위치해 있다면(그림 2 참고), 다음 이동에서는 (1;3), (3;3), (4;2) 중 한 칸으로 이동할 수 있습니다.

입력으로 자연수 n, m, i, j(n<=100, m<=100, i<=n, j<=m)가 주어질 때, 나이트가 (1;1)에서 출발하여 (i;j) 칸에 도달하는 데 필요한 최소 이동 횟수를 구해 출력하세요.

만약 해당 칸에 도달할 수 없다면, "NEVAR"라는 단어만 출력하세요.



그림 1



그림 2

예제 입력 1
5 3 1 2
예제 출력 1
3
예제 입력 2
100 2 2 2
예제 출력 2
NEVAR
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ti, tj;
    if(!(cin >> n >> m >> ti >> tj)) return 0;

    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));
    const int dr[8] = {1,1,-1,-1,2,2,-2,-2};
    const int dc[8] = {2,-2,2,-2,1,-1,1,-1};

    queue<pair<int,int>> q;
    dist[1][1] = 0;
    q.push({1,1});

    while(!q.empty()){
        auto [r,c] = q.front(); q.pop();
        if(r == ti && c == tj) break;
        for(int k=0;k<8;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 1 && nr <= n && nc >= 1 && nc <= m && dist[nr][nc] == -1){
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }

    if(dist[ti][tj] == -1) cout << "NEVAR\n";
    else cout << dist[ti][tj] << '\n';

    return 0;
}
