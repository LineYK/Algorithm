#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string l, r;
    if (!(cin >> l)) return 0;
    if (!(cin >> r)) return 0;

    if (l.size() < r.size()) {
        cout << r.size() << '\n';
        return 0;
    }
    int n = (int)l.size();
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if (l[i] != r[i]) { idx = i; break; }
    }
    if (idx == -1) cout << 0 << '\n';
    else cout << (n - idx) << '\n';
    return 0;
}
