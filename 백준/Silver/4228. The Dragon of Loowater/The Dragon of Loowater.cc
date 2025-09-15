#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int n, m;
        if (!(cin >> n >> m)) return 0;
        if (n == 0 && m == 0) break;

        vector<int> heads(n), knights(m);
        for (int i = 0; i < n; ++i) cin >> heads[i];
        for (int i = 0; i < m; ++i) cin >> knights[i];

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        ll cost = 0;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (knights[j] >= heads[i]) {
                cost += knights[j];
                ++i; ++j;
            } else {
                ++j;
            }
        }
        if (i == n) {
            cout << cost << '\n';
        } else {
            cout << "Loowater is doomed!\n";
        }
    }
    return 0;
}
