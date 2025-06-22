#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, C;
    cin >> S >> C;
    vector<ll> L(S);
    ll total = 0;
    for(int i = 0; i < S; i++){
        cin >> L[i];
        total += L[i];
    }

    ll lo = 1, hi = *max_element(L.begin(), L.end()), best = 0;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(int i = 0; i < S; i++){
            cnt += L[i] / mid;
            if(cnt >= C) break;
        }
        if(cnt >= C){
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    ll used = (ll)C * best;
    cout << (total - used) << "\n";
    return 0;
}
