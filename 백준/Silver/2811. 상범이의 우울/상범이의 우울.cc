/*
상범이의 우울
 
시간 제한	메모리 제한
1 초	128 MB	

문제
민균이와 상범이는 오래된 연인이다.

요즘따라 냉랭해진 상범이의 태도를 본 민균이는 상범이의 기분을 예측한 다음, 상범이가 우울해지기 전에 꽃을 선물함으로써 그의 기분을 상큼하게 만들어주려고 한다.

상범이의 기분은 하루씩 정수로 표현되는데, 기분이 좋은 날은 양수로 표현되고 우울한 날은 음수로 표현된다. (따라서 음수만 나타나는 연속적인 구간을 '우울한 기간' 또는 '우울 기간'이라고 한다)

한편, 상범이의 우울 기간의 길이가 T일 땐, 구간의 시작으로부터 2T일 전부터 구간의 시작 바로 전날까지 꽃을 선물해야 그의 우울함을 덜어줄 수 있다. 주의해야 할 점은 길이가 가장 긴 우울 구간의 경우에는 2T일 이전이 아닌 3T일 이전부터 꽃을 선물해야 한다는 점이다. 현재부터 가장 빠른 상범이의 우울기간을 T_f 라고 하자. 만약 현재부터 계속해서 꽃을 선물해도 가장 빠른 상범이의 우울기간까지 2 * T_f 만큼 꽃을 선물할 수 없다고 하더라고 줄 수 있는만큼 꽃을 줘야 한다. (단, 이런 최장 우울 구간이 여러 개인 경우에는 그중 한 구간만 이렇게 하면 되고, 나머지 구간은 2T로 적용하면 된다)

민균이가 예측한 앞으로 N일간의 상범이의 기분이 주어졌을 때, 이 N일 중 그가 상범이에게 꽃을 줘야하는 날의 수(사야 하는 꽃의 개수)의 최댓값을 구해보자.

입력
첫 번째 줄에는 예측한 날의 수 N (1 ≤ N ≤ 100,000)이 주어진다.

두 번째 줄에는 상범이의 기분을 나타내는 N개의 정수(|기분| ≤ 100)가 주어진다.

출력
민균이가 상범이에게 꽃을 주어야하는 날의 최댓값을 출력한다.

예제 입력 1 
8
1 -1 4 3 8 -2 3 -3
예제 출력 1 
6
예제 입력 2 
15
1 2 -1 2 3 4 5 6 1 4 8 3 -1 -2 1
예제 출력 2 
8
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> mood(N);
    for(int i = 0; i < N; i++) {
        cin >> mood[i];
    }

    vector<pair<int,int>> P;
    for(int i = 0; i < N; ){
        if(mood[i] < 0){
            int s = i, len = 0;
            while(i < N && mood[i] < 0){
                ++len; ++i;
            }
            P.emplace_back(s, len);
        } else {
            ++i;
        }
    }
    if(P.empty()){
        cout << 0 << "\n";
        return 0;
    }

    int maxT = 0;
    for(auto &pr: P) maxT = max(maxT, pr.second);

    vector<pair<int,int>> seg2;
    seg2.reserve(P.size());
    for(auto &pr: P){
        int s = pr.first, T = pr.second;
        int L = max(0, s - 2*T), R = s - 1;
        if(L <= R) seg2.emplace_back(L, R);
    }
    if(seg2.empty()){
        ll base = 0;
        ll bestExtra = 0;
        for(auto &pr: P){
            int s = pr.first, T = pr.second;
            int L3 = max(0, s - 3*T), R = s - 1;
            if(L3 <= R) bestExtra = max<ll>(bestExtra, R - L3 + 1);
        }
        cout << base + bestExtra << "\n";
        return 0;
    }

    sort(seg2.begin(), seg2.end());
    vector<pair<int,int>> merged;
    for(auto &s2: seg2){
        if(merged.empty() || s2.first > merged.back().second + 1){
            merged.push_back(s2);
        } else {
            merged.back().second = max(merged.back().second, s2.second);
        }
    }
    ll base = 0;
    for(auto &m: merged){
        base += (m.second - m.first + 1);
    }

    ll bestExtra = 0;
    for(auto &pr: P){
        int s = pr.first, T = pr.second;
        if(T != maxT) continue;
        int L3 = max(0, s - 3*T), L2 = max(0, s - 2*T);
        int R = s - 1;
        if(L3 > R) continue;
        ll extraLen = (ll)R - L3 + 1;
        ll overlap = 0;
        for(auto &m: merged){
            if(m.second < L3) continue;
            if(m.first > R) break;
            int a = max(m.first, L3);
            int b = min(m.second, R);
            overlap += (b - a + 1);
        }
        ll extra = extraLen - overlap;
        bestExtra = max(bestExtra, extra);
    }

    cout << base + bestExtra << "\n";
    return 0;
}