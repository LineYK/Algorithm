#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<tuple<int,int,int>> times;
    times.reserve(N);

    for (int i = 0; i < N; ++i) {
        int h, m, s;
        cin >> h >> m >> s;
        times.emplace_back(h, m, s);
    }

    sort(times.begin(), times.end());

    for (auto &t : times) {
        int h, m, s;
        tie(h, m, s) = t;
        cout << h << ' ' << m << ' ' << s << '\n';
    }
    return 0;
}