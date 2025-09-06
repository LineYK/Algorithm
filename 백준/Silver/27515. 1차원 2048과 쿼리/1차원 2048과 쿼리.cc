#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    if(!(cin >> Q)) return 0;

    static long long cnt[63];
    for(int i=0;i<63;i++) cnt[i]=0;

    while(Q--){
        char sign;
        unsigned long long x;
        cin >> sign >> x;
        if(x != 0){
            int k = __builtin_ctzll(x);
            if(sign == '+') cnt[k]++;
            else cnt[k]--;
        } else {
        }

        long long carry = 0;
        int maxk = -1;
        for(int k=0;k<=62;k++){
            long long cur = cnt[k] + carry;
            if((cur & 1LL) == 1LL) maxk = k;
            carry = cur >> 1; 
        }
        if(maxk == -1) cout << 0 << '\n';
        else cout << ( (1ULL << maxk) ) << '\n';
    }
    return 0;
}
