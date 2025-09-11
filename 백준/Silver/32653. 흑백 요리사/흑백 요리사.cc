#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 gcd_int64(int64 a, int64 b){
    while(b){
        int64 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;
    vector<int> x(N);
    for(int i=0;i<N;i++) cin >> x[i];

    int64 L = 1;
    for(int i=0;i<N;i++){
        int64 v = 2LL * x[i];
        int64 g = gcd_int64(L, v);
        __int128 tmp = (__int128)(L / g) * (__int128)v;
        L = (int64)tmp;
    }

    cout << L << '\n';
    return 0;
}