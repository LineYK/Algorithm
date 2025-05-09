/*
마블 매드니스
 
시간 제한 메모리 제한
1초 256MB

문제
오이빈드는 특히 재미있는 게임으로 미래의 직원들을 테스트하는 것을 좋아합니다. 이번에는 가방에 검은색 구슬 B와 흰색 구슬 W를 가지고 시작하는 게임을 발명했습니다. 또한 가방 밖에는 두 종류의 구슬이 무한히 있습니다. 게임은 라운드로 진행됩니다. 각 라운드마다 가방에서 무작위로 두 개의 구슬을 꺼내고, 다음 규칙에 따라 한 개의 구슬(꺼낸 두 개 중 다른 색일 수도 있음)을 다시 넣습니다:

흰색 구슬 두 개를 꺼내면 검은색 구슬을 다시 넣습니다.
검은색과 흰색 구슬을 각각 하나씩 꺼냈을 때는 흰색 구슬을 다시 넣습니다.
검은색 구슬 두 개를 꺼내면 검은색 구슬을 다시 넣습니다.
이 게임이 끝나면 가방에는 구슬이 하나만 남게 됩니다. 이 구슬은 각 색깔의 구슬의 개수에 따라 일정 확률로 흰색일 수도 있고 검은색일 수도 있습니다. 여러분의 임무는 이 확률을 찾는 것입니다.

입력
입력은 테스트 케이스의 수인 T를 나타내는 한 줄로 시작됩니다. 각 테스트 케이스는 각각 검은색과 흰색 구슬의 수를 나타내는 두 개의 정수 B와 W가 한 칸으로 구분되어 한 줄에 제시됩니다.

0 < T ≤ 100
0 ≤ B, W ≤ 50000
0 < B + W
정답의 10-6 이내의 모든 답이 허용됩니다.
출력
각 테스트 케이스마다 두 개의 부동 소수점 숫자가 공백으로 구분된 한 줄의 출력이 있어야 합니다. 첫 번째 숫자는 마지막 구슬이 검은색일 확률을, 두 번째 숫자는 마지막 구슬이 흰색일 확률을 나타내야 합니다.

예제 입력 1 
2
1 1
3 0
예제 출력 1 
0.00 1.00
1.00 0.00
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while(T--){
        int B, W;
        cin >> B >> W;
        
        if(W % 2 == 0){
            cout << fixed << setprecision(6) << 1.000000 << " " << 0.000000 << "\n";
        } else {
            cout << fixed << setprecision(6) << 0.000000 << " " << 1.000000 << "\n";
        }
    }
    
    return 0;
}