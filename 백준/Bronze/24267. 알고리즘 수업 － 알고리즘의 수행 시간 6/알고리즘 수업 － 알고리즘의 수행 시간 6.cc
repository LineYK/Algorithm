#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    if(!(cin >> n)) return 0;
    long long cnt = 0;
    if (n >= 3) cnt = n * (n - 1) * (n - 2) / 6;
    cout << cnt << '\n' << 3 << '\n';
    return 0;
}