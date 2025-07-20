/*
배고파(Hard)
 
시간 제한	메모리 제한
1 초	1024 MB	

문제
이 문제는 배고파(Easy)의 상위 문제이고, 배고파(Easy)에 이 문제의 정답 코드를 제출하여 맞힐 수 있다.

송도고등학교는 경관이 참 예쁘다. 도훈이는 특히 학교 뒤쪽에 만개한 벚꽃을 보고 감탄하였다.

2021년 봄에 찍은 송도고등학교 뒤쪽 벚꽃 나무들의 풍경이다.

남고에서 만개한 벚꽃을 보고 있자니 괜스레 속이 쓰린 도훈이는 밥이나 먹어야겠다고 생각했다. 그런데 도훈이에게는 치료가 필요할 정도로 심각한 결정 장애가 있어서 메뉴를 고르는 것이 쉽지 않다. 따라서 도훈이는 n개의 메뉴를 각각 다음과 같은 규칙으로 골라 먹을 생각이다.

주어진 양의 정수 m에 대해 2^x + 2^y = m인 음이 아닌 정수 x와 y를 찾은 뒤 메뉴판의 (x,y) 위치에 적힌 메뉴를 고른다. 단, x\le y인 경우만 다룬다.
그런 (x,y)가 존재하지 않는다면, (x,y)가 존재하는 m과의 차이가 가장 작은 수로 m을 대체한 뒤 위와 같은 규칙으로 메뉴판의 (x,y) 위치에 적힌 메뉴를 고른다. 대체할 수 있는 수가 여러 가지라면 그중 가장 작은 것으로 대체한다. 이때 (x,y)가 유일하게 결정됨을 증명할 수 있다.
하지만 도훈이는 n과 m이 너무 커서 메뉴를 주문하는 데 어려움을 겪고 있다. 도훈이를 도와 n개의 메뉴를 주문하는 프로그램을 작성하여라.

입력
첫 번째 줄에 메뉴의 수 n이 주어진다.

이어서 n개의 각 줄에 메뉴를 고를 때 사용할 양의 정수 m이 하나씩 주어진다.

출력
n개의 줄에 각각 주문할 메뉴의 위치 (x,y)의 x, y를 공백으로 구분하여 출력한다.

제한
1\le n\le 10\,000.
1\le m\le 10^{18}.
주어진 m에 대해 x\le y인 (x,y) 순서쌍이 존재하지 않을 수 있다.
예제 입력 1 
2
7
1
예제 출력 1 
1 2
0 0
첫 번째 메뉴를 고르는 과정은 다음과 같다.

7은 2^x+2^y 꼴로 표현할 수 없다.
2^2+2^2=8이므로, 8은 2^x+2^y 꼴로 표현 가능하다.
2^1+2^2=6이므로, 6은 2^x+2^y 꼴로 표현 가능하다.
따라서 도훈이는 m을 6 또는 8로 대체할 수 있는데, 둘 다 m과의 차이가 같기 때문에 더 작은 6으로 대체한다.

두 번째 메뉴를 고르는 과정은 다음과 같다.

1은 2^x+2^y 꼴로 표현할 수 없다.
2^0+2^0=2이므로, 2는 2^x+2^y 꼴로 표현 가능하다.
따라서 도훈이는 m을 2로 대체한다.

노트
2^0=1이고, 양의 정수 n에 대해 
2^n = \overbrace{2\times 2\times \cdots \times 2}^{n}로 정의된다.
C/C++의 경우, 32bit 정수형 int의 범위를 넘어가는 정수를 다루게 되므로 64bit 정수형 long long 사용을 권장한다.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<ll, pair<int,int>>> A;
    for(int y = 0; y <= 60; ++y){
        ll py = 1LL << y;
        for(int x = 0; x <= y; ++x){
            ll px = 1LL << x;
            ll M = px + py;
            A.push_back({M, {x, y}});
        }
    }
    sort(A.begin(), A.end(), [](auto &a, auto &b){
        return a.first < b.first;
    });

    int n;
    cin >> n;
    while(n--){
        ll m;
        cin >> m;
        auto it = lower_bound(A.begin(), A.end(), m,
            [](auto &elem, ll value){
                return elem.first < value;
            });
        pair<ll,pair<int,int>> best;
        bool hasL = false, hasR = false;

        if(it != A.end()){
            best = *it;
            hasR = true;
        }
        if(it != A.begin()){
            auto itl = prev(it);
            if(!hasR){
                best = *itl;
            } else {
                ll dR = llabs(it->first - m);
                ll dL = llabs(itl->first - m);
                if(dL < dR || (dL == dR && itl->first < it->first))
                    best = *itl;
            }
            hasL = true;
        }
        cout << best.second.first
             << ' '
             << best.second.second
             << '\n';
    }
    return 0;
}
