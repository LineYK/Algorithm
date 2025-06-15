#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        ull r, t;
        cin >> r >> t;

        ull lo = 0, hi = min<ull>( (t/(2*r+1))+1, t ); 

        while(lo < hi){
            ull mid = lo + (hi - lo + 1) / 2;
            __int128 need = (__int128)mid * (2*r + 2*mid - 1);
            if(need <= t) lo = mid;
            else         hi = mid - 1;
        }

        cout << "Case #" << tc << ": " << lo << "\n";
    }
    return 0;
}
