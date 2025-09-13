/*
직각삼각형
 
시간 제한	메모리 제한
5 초	256 MB	

문제
2차원 평면에 N개의 점이 주어져 있다. 이 중에서 세 점을 골랐을 때, 직각삼각형이 몇 개나 있는지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N(3 ≤ N ≤ 1,500)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 점의 x좌표와 y좌표가 빈 칸을 사이에 두고 주어진다. 좌표값은 절댓값이 1,000,000,000을 넘지 않는 정수이며, 주어지는 모든 점의 좌표는 다르다.

출력
첫째 줄에 직각삼각형의 개수를 출력한다.

예제 입력 1 
5
-1 1
-1 0
0 0
1 0
1 1
예제 출력 1 
7
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll llgcd(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}


inline ll packKey(int x, int y) {
    return ((ll)(int)x << 32) ^ (unsigned int)(y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;
    vector<ll> X(N), Y(N);
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i];
    }

    ll total = 0;

    for(int p = 0; p < N; ++p){
        vector<pair<int,int>> dirs; dirs.reserve(N-1);
        unordered_map<ll,int> freq;
        freq.reserve((N-1)*2);

        for(int q = 0; q < N; ++q){
            if(q == p) continue;
            ll dx = X[q] - X[p];
            ll dy = Y[q] - Y[p];
            ll g = llgcd(dx, dy);
            dx /= g; dy /= g; 

            int ux = (int)dx;
            int uy = (int)dy;
            
            if(ux < 0 || (ux == 0 && uy < 0)){
                ux = -ux; uy = -uy;
            }
            dirs.emplace_back(ux, uy);
            ll key = packKey(ux, uy);
            ++freq[key];
        }

        ll cntPairsDouble = 0;
        for(auto &pr : dirs){
            int ux = pr.first, uy = pr.second;
            int ox = -uy, oy = ux;
            if(ox < 0 || (ox == 0 && oy < 0)){
                ox = -ox; oy = -oy;
            }
            ll keyo = packKey(ox, oy);
            auto it = freq.find(keyo);
            if(it != freq.end()) cntPairsDouble += it->second;
        }

        total += cntPairsDouble / 2;
    }

    cout << total << '\n';
    return 0;
}
