#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int W, H;
    if (!(cin >> W >> H)) return 0;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) cin >> grid[i];

    vector<vector<char>> vis(H, vector<char>(W, 0));
    int dx[8] = {1,-1,0,0,1,1,-1,-1};
    int dy[8] = {0,0,1,-1,1,-1,1,-1};

    int best = 0;
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (!vis[r][c] && grid[r][c] == '.') {
                // BFS from (r,c)
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push({r,c});
                vis[r][c] = 1;
                while (!q.empty()) {
                    auto [x,y] = q.front(); q.pop();
                    ++cnt;
                    for (int k = 0; k < 8; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                            if (!vis[nx][ny] && grid[nx][ny] == '.') {
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                best = max(best, cnt);
            }
        }
    }

    cout << best << '\n';
    return 0;
}
