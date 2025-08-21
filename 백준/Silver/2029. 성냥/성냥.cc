#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> raw;
    string line;
    // 읽어서 공백 제거한 뒤 10개의 행을 확보
    while ((int)raw.size() < 10 && getline(cin, line)) {
        string t;
        for(char ch: line) if(!isspace((unsigned char)ch)) t.push_back(ch);
        if(!t.empty()) raw.push_back(t);
    }
    if((int)raw.size() < 10){
        // 입력이 부족하면 종료 (안나올 상황)
        return 0;
    }
    // 각 줄을 길이 10으로 맞춤(만약 더 길면 앞 10만 사용)
    vector<string> g(10);
    for(int i=0;i<10;i++){
        if((int)raw[i].size() < 10){
            // 짧으면 오른쪽을 '.'로 채움 (안 나올 상황이지만 안전 처리)
            raw[i] += string(10 - raw[i].size(), '.');
        }
        g[i] = raw[i].substr(0,10);
    }

    // hor[r][c]: 노드 행 r(0..3), 노드 열 시작 c(0..2) 에서의 가로 성냥 존재 여부
    bool hor[4][3] = {0};
    // vert[r][c]: 노드 행 시작 r(0..2), 노드 열 c(0..3) 에서의 세로 성냥 존재 여부
    bool vert[3][4] = {0};

    // detect horizontals
    for(int rnode = 0; rnode < 4; ++rnode){
        int r = rnode * 3;
        for(int cstart = 0; cstart < 3; ++cstart){
            int c1 = cstart*3 + 1;
            int c2 = cstart*3 + 2;
            if(g[r][c1] == '-' && g[r][c2] == '-') hor[rnode][cstart] = true;
        }
    }
    // detect verticals
    for(int cnode = 0; cnode < 4; ++cnode){
        int c = cnode * 3;
        for(int rstart = 0; rstart < 3; ++rstart){
            int r1 = rstart*3 + 1;
            int r2 = rstart*3 + 2;
            if(g[r1][c] == '|' && g[r2][c] == '|') vert[rstart][cnode] = true;
        }
    }

    // count present matches
    int present = 0;
    for(int i=0;i<4;i++) for(int j=0;j<3;j++) if(hor[i][j]) present++;
    for(int i=0;i<3;i++) for(int j=0;j<4;j++) if(vert[i][j]) present++;
    int A = 24 - present;

    // count squares B
    int B = 0;
    // side length in nodes = k (number of edges along side). k = 1..3
    for(int k = 1; k <= 3; ++k){
        for(int r = 0; r + k < 4; ++r){
            for(int c = 0; c + k < 4; ++c){
                bool ok = true;
                // top horizontal: hor[r][c..c+k-1]
                for(int t = 0; t < k; ++t) if(!hor[r][c+t]) { ok = false; break; }
                if(!ok) continue;
                // bottom horizontal: hor[r+k][c..c+k-1]
                for(int t = 0; t < k; ++t) if(!hor[r+k][c+t]) { ok = false; break; }
                if(!ok) continue;
                // left vertical: vert[r..r+k-1][c]
                for(int t = 0; t < k; ++t) if(!vert[r+t][c]) { ok = false; break; }
                if(!ok) continue;
                // right vertical: vert[r..r+k-1][c+k]
                for(int t = 0; t < k; ++t) if(!vert[r+t][c+k]) { ok = false; break; }
                if(ok) B++;
            }
        }
    }

    cout << A << " " << B << "\n";
    return 0;
}