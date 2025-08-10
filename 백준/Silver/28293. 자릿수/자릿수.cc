#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a;
    long long b;
    if(!(cin >> a >> b)) return 0;

    if (a == 0) { // 문제 제약상 a >= 1 이지만 안전히 처리
        cout << 1 << '\n';
        return 0;
    }

    if (a == 1) {
        cout << 1 << '\n';
        return 0;
    }

    long double la = (long double)a;
    long double lb = (long double)b;
    long double x = lb * log10l(la);

    const long double eps = 1e-12L;
    long long digits = (long long)floor(x + eps) + 1;
    cout << digits << '\n';
    return 0;
}