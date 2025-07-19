#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int U, V;
    cin >> U >> V;
    vector<string> tex(U);
    for(int i = 0; i < U; i++){
        cin >> tex[i];
    }
    string mode;
    cin >> mode;

    for(int i = 0; i < N; i++){
        string line;
        line.reserve(M);
        for(int j = 0; j < M; j++){
            int r, c;
            if(mode == "clamp-to-edge"){
                r = min(i, U-1);
                c = min(j, V-1);
            }
            else if(mode == "repeat"){
                r = i % U;
                c = j % V;
            }
            else {
                int br = i / U;
                int bc = j / V;
                int r0 = i % U;
                int c0 = j % V;
                if(br % 2 == 0)      r = r0;
                else                 r = (U-1) - r0;
                if(bc % 2 == 0)      c = c0;
                else                 c = (V-1) - c0;
            }
            line.push_back(tex[r][c]);
        }
        cout << line << "\n";
    }
    return 0;
}