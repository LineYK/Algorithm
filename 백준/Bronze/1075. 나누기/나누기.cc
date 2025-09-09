#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    int F;
    if(!(cin >> N)) return 0;
    cin >> F;
    long long base = N - (N % 100);
    int ans = 0;
    for(int x = 0; x <= 99; ++x){
        if( (base + x) % F == 0 ){
            ans = x;
            break;
        }
    }
    cout << setw(2) << setfill('0') << ans << '\n';
    return 0;
}
