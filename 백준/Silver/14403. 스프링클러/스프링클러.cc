/*
스프링클러
 
시간 제한   메모리 제한
2 초   512 MB

문제
영선이는 마당에서 꽃을 키운다. 영선이는 자연스럽게 키우는 것을 좋아하기에 꽃을 최대한 자연스럽게, 잡초 마냥, 이곳 저곳에 심었다. 그러나 꽃을 너무 이곳 저곳에 심어 꽃에 물을 주기가 힘들게 되었다.

그래서 영선이는 스프링클러를 2개를 사와서 설치를 하였다. 각 스프링클러는 각자 r1,r2을 반지름을 갖는 원 영역만큼 물을 뿌린다. 영선이는 이 물이 뿌려지는 원의 반지름을 조절하여 모든 꽃에 물을 뿌리려 한다. 모든 꽃은 둘 중 한 군데에서라도 물을 받으면 된다. 꽃이 스프링클러에서 물을 받으려면 꽃과 스프링클러의 좌표를 (x1,y1),(x2,y2)라고 할 때, sqrt((x1-x2)^2+(y1-y2)^2) ≤ r 이어야 한다.

물이 뿌려지는 것은 원의 영역이기 때문에 (r1^2+r2^2)*π만큼 뿌려지는데, 물을 아끼기 위하여 저 값을 최소로 하고 싶다. 하지만 계산의 편의상 π는 무시하고 계산한다. 따라서 r1^2+r2^2의 값을 최소로 할 때, 그 값을 출력하시오.

입력
첫째 줄에는 꽃의 개수 n, 두 스프링클러의 좌표 x1,y1,x2,y2가 주어진다.(1≤n≤2000, -1,000,000≤ x1,y1,x2,y2 ≤ 1,000,000)

다음 n줄에는 각 꽃의 좌표 x,y가 주어진다. 모든 꽃과 스프링클러의 좌표는 다름이 보장된다.(-1,000,000 ≤ x,y ≤ 1,000,000)

출력
r1^2+r2^2의 값을 최소로 할 때, 그 값을 출력하시오.

예제 입력 1 
4 0 0 5 0
9 4
8 3
-1 0
1 4
예제 출력 1 
33
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll x1,y1,x2,y2;
    if(!(cin >> n >> x1 >> y1 >> x2 >> y2)) return 0;

    vector<pair<ll,ll>> pts(n);
    for(int i=0;i<n;i++){
        ll x,y; cin >> x >> y;
        pts[i] = {x,y};
    }

    vector<ll> d1(n), d2(n);
    for(int i=0;i<n;i++){
        ll dx1 = pts[i].first - x1;
        ll dy1 = pts[i].second - y1;
        d1[i] = dx1*dx1 + dy1*dy1;
        ll dx2 = pts[i].first - x2;
        ll dy2 = pts[i].second - y2;
        d2[i] = dx2*dx2 + dy2*dy2;
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
        return d1[a] < d1[b];
    });

    vector<ll> d1s(n), d2s(n);
    for(int i=0;i<n;i++){
        d1s[i] = d1[idx[i]];
        d2s[i] = d2[idx[i]];
    }

    vector<ll> suf(n+1, 0);
    for(int i=n-1;i>=0;i--){
        suf[i] = max(suf[i+1], d2s[i]);
    }

    ll ans = LLONG_MAX;
    for(int k=0;k<=n;k++){
        ll r1sq = (k==0 ? 0 : d1s[k-1]);
        ll r2sq = suf[k]; 
        ans = min(ans, r1sq + r2sq);
    }

    cout << ans << "\n";
    return 0;
}
