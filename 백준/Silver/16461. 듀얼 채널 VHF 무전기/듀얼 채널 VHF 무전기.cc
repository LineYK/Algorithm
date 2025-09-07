#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

ll to_int_kHz(const string &s){
    int a = stoi(s.substr(0, s.find('.')));
    string dec = s.substr(s.find('.')+1);
    while(dec.size() < 3) dec += '0';
    int d = stoi(dec.substr(0,3));
    return (ll)a*1000 + d;
}

ll steps_up(ll s, ll t){
    if(s == t) return 0;
    if(t >= s && (t - s) % 20 == 0) return (t - s) / 20; 
    ll K = (146000 - s) / 20;
    ll k1 = K + 1; 
    if(t >= 144000 && (t - 144000) % 20 == 0) {
        ll j = (t - 144000) / 20;
        return k1 + j;
    }
    return INF;
}

ll steps_down(ll s, ll t){
    if(s == t) return 0;
    if(t <= s && (s - t) % 20 == 0) return (s - t) / 20; 
    ll K = (s - 144000) / 20;
    ll k1 = K + 1; 
    if(t <= 146000 && (146000 - t) % 20 == 0) {
        ll j = (146000 - t) / 20;
        return k1 + j;
    }
    return INF;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    if(!(cin >> TC)) return 0;
    while(TC--){
        string A_s, B_s, cur_s, T_s;
        cin >> A_s >> B_s >> cur_s >> T_s;
        ll A = to_int_kHz(A_s);
        ll B = to_int_kHz(B_s);
        ll T = to_int_kHz(T_s);
        char cur = cur_s[0];

        ll ans = INF;
        if( (cur == 'A' && A == T) || (cur == 'B' && B == T) ) ans = 0;
        else if( (cur == 'A' && B == T) || (cur == 'B' && A == T) ) ans = min(ans, 1LL);

        ll costA_keypad = (cur == 'A' ? 0 : 1) + 6;
        ll costB_keypad = (cur == 'B' ? 0 : 1) + 6;
        ans = min(ans, min(costA_keypad, costB_keypad));

        ll costA_up = INF, costB_up = INF;
        {
            ll need = steps_up(A, T);
            if(need < INF) costA_up = need + (cur == 'A' ? 0 : 1);
        }
        {
            ll need = steps_up(B, T);
            if(need < INF) costB_up = need + (cur == 'B' ? 0 : 1);
        }
        ans = min(ans, min(costA_up, costB_up));

        ll costA_down = INF, costB_down = INF;
        {
            ll need = steps_down(A, T);
            if(need < INF) costA_down = need + (cur == 'A' ? 0 : 1);
        }
        {
            ll need = steps_down(B, T);
            if(need < INF) costB_down = need + (cur == 'B' ? 0 : 1);
        }
        ans = min(ans, min(costA_down, costB_down));

        cout << ans << '\n';
    }
    return 0;
}