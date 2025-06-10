#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // 1) 기본 행렬식
    long long D = a * e - b * d;

    // 2) 분자 행렬식
    long long Dx = c * e - b * f;
    long long Dy = a * f - c * d;

    // 3) 해 계산 (정수로 떨어짐이 보장됨)
    long long x = Dx / D;
    long long y = Dy / D;

    cout << x << " " << y << "\n";
    return 0;
}