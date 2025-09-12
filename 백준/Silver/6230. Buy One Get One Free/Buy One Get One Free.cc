#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> high(N), low(M);
    for (int i = 0; i < N; ++i) cin >> high[i];
    for (int i = 0; i < M; ++i) cin >> low[i];

    sort(high.begin(), high.end());
    sort(low.begin(), low.end());

    int j = 0; 
    int matched = 0;
    for (int i = 0; i < N && j < M; ++i) {
        if (low[j] < high[i]) {
            matched++;
            j++;
        } else {
            continue;
        }
    }

    cout << (N + matched) << '\n';
    return 0;
}
