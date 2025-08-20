#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long M, K;
    if(!(cin >> M >> K)) return 0;
    cout << (M % K == 0 ? "Yes" : "No") << '\n';
    return 0;
}