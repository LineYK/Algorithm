#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const string T = "welcome to code jam";
    const int L = T.size();
    const int MOD = 10000;

    int TC;
    if (!(cin >> TC)) return 0;
    string line;
    getline(cin, line); 

    for (int tc = 1; tc <= TC; ++tc) {
        getline(cin, line);
        vector<int> dp(L+1, 0);
        dp[0] = 1;
        for (char ch : line) {
            for (int j = L; j >= 1; --j) {
                if (ch == T[j-1]) {
                    dp[j] = (dp[j] + dp[j-1]) % MOD;
                }
            }
        }
        int ans = dp[L] % MOD;
        ostringstream oss;
        oss << setw(4) << setfill('0') << ans;
        cout << "Case #" << tc << ": " << oss.str() << '\n';
    }
    return 0;
}
