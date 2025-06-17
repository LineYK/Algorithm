/*
섬
 
시간 제한 메모리 제한
2 초 512 MB

문제
위성을 사용하여 멀리 떨어진 행성을 매핑하고 있습니다. 행성의 표면은 그리드로 모델링할 수 있습니다. 위성이 표면의 이미지를 캡처했습니다. 각 격자 사각형은 육지('L'로 표시), 물('W'로 표시) 또는 구름('C'로 표시)으로 덮여 있습니다. 구름은 지표면이 육지일 수도 있고 물일 수도 있지만 구분할 수 없음을 의미합니다.

섬은 섬의 모든 격자 셀이 어떤 경로로 서로 연결되어 있고 경로의 모든 다리가 위, 아래, 왼쪽 또는 오른쪽으로만 연결되는 육지 영역입니다.

이미지가 주어졌을 때, 주어진 이미지와 일치하는 섬의 최소 개수를 구합니다.

입력
각 입력은 하나의 테스트 케이스로 구성됩니다. 프로그램은 서로 다른 입력에서 여러 번 실행될 수 있습니다. 입력의 첫 번째 줄에는 이미지의 행 수와 열 수인 두 개의 정수 r과 c(1 ≤ r,c ≤ 50)가 포함됩니다. 다음 r 줄에는 각각 정확히 c 문자가 포함되며, ‘L’(땅을 나타내는), ‘W’(물을 나타내는), ‘C’(구름을 나타내는)로만 구성됩니다.

출력
가능한 섬의 최소 개수인 정수를 하나 출력합니다.

예제 입력 1 
4 5
CCCCC
CCCCC
CCCCC
CCCCC
예제 출력 1 
0
예제 입력 2 
3 2
LW
CC
WL
예제 출력 2 
1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;
    vector<string> G(r);
    for(int i = 0; i < r; i++){
        cin >> G[i];
    }

    vector<vector<bool>> vis(r, vector<bool>(c,false));
    int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};
    int ans = 0;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if (!vis[i][j] && (G[i][j]=='L' || G[i][j]=='C')) {
                bool hasL = false;
                // BFS
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = true;
                if (G[i][j]=='L') hasL = true;

                while(!q.empty()){
                    auto [x,y] = q.front(); q.pop();
                    for(int d=0; d<4; d++){
                        int nx = x + dr[d];
                        int ny = y + dc[d];
                        if (nx<0||nx>=r||ny<0||ny>=c) continue;
                        if (vis[nx][ny]) continue;
                        if (G[nx][ny]=='W') continue;  // 물은 건너뛴다
                        vis[nx][ny] = true;
                        if (G[nx][ny]=='L') hasL = true;
                        q.push({nx,ny});
                    }
                }

                if (hasL) ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
