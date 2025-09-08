#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000009LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    vector<pair<int,int>> qs;
    qs.reserve(T);
    int maxN = 0, maxM = 0;
    for (int i = 0; i < T; ++i) {
        int n, m;
        cin >> n >> m;
        qs.emplace_back(n, m);
        maxN = max(maxN, n);
        maxM = max(maxM, m);
    }

 
    vector<vector<ll>> dp(maxN+1, vector<ll>(maxM+1, 0));
    dp[0][0] = 1;
    for (int k = 1; k <= maxM; ++k) {
        for (int s = 1; s <= maxN; ++s) {
            ll val = 0;
            if (s - 1 >= 0) val += dp[s-1][k-1];
            if (s - 2 >= 0) val += dp[s-2][k-1];
            if (s - 3 >= 0) val += dp[s-3][k-1];
            dp[s][k] = val % MOD;
        }
    }

    for (auto &pr : qs) {
        int n = pr.first, m = pr.second;
        cout << dp[n][m] % MOD << '\n';
    }
    return 0;
}