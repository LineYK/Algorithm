#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string target;
    cin >> N >> target;
    int m = (int)target.size();
    int ans = 0;

    while (N--) {
        string s;
        cin >> s;
        int L = (int)s.size();
        bool possible = false;
        // 시작 위치 i에서 간격 d를 고정하여 target과 매칭
        for (int i = 0; i < L && !possible; ++i) {
            if (s[i] != target[0]) continue;
            // 최대 간격 d: i + (m-1)*d < L  => d <= (L-1-i)/(m-1)
            if (m == 1) {
                possible = true;
                break;
            }
            int maxd = (L - 1 - i) / (m - 1);
            for (int d = 1; d <= maxd && !possible; ++d) {
                bool ok = true;
                for (int j = 1; j < m; ++j) {
                    if (s[i + j * d] != target[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) possible = true;
            }
        }
        if (possible) ++ans;
    }

    cout << ans;
    return 0;
}
