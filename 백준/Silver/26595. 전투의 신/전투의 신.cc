#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    ll A, P_A, B, P_B;
    cin >> A >> P_A >> B >> P_B;

    ll bestPower = -1;
    ll bestX = 0, bestY = 0;

    ll maxY = N / P_B;
    for(ll y = 0; y <= maxY; ++y){
        ll remain = N - P_B * y;
        ll x = remain >= 0 ? (remain / P_A) : 0;
        ll powerSum = A * x + B * y;
        if(powerSum > bestPower){
            bestPower = powerSum;
            bestX = x;
            bestY = y;
        }
    }

    cout << bestX << " " << bestY << "\n";
    return 0;
}