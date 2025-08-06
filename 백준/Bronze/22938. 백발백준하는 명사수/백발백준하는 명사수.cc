#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x1,y1,r1, x2,y2,r2;
    cin >> x1 >> y1 >> r1
        >> x2 >> y2 >> r2;

    ll dx = x1 - x2;
    ll dy = y1 - y2;
    ll D = dx*dx + dy*dy;

    ll S = r1 + r2;        // 반지름 합
    ll d = llabs(r1 - r2); // 반지름 차

    if (D < S*S && D != d*d)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}