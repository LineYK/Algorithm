#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> A;

void compress(int r, int c, int sz) {
    char first = A[r][c];
    bool same = true;
    for (int i = r; i < r + sz && same; ++i) {
        for (int j = c; j < c + sz; ++j) {
            if (A[i][j] != first) { same = false; break; }
        }
    }
    if (same) {
        cout << first;
        return;
    }
    int h = sz / 2;
    cout << '(';
    compress(r, c, h);             // 왼쪽 위
    compress(r, c + h, h);         // 오른쪽 위
    compress(r + h, c, h);         // 왼쪽 아래
    compress(r + h, c + h, h);     // 오른쪽 아래
    cout << ')';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> N)) return 0;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    compress(0, 0, N);
    cout << '\n';
    return 0;
}