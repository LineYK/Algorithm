/*
프리셀 통계(대형)
 
시간 제한 메모리 제한	
5초 512MB	

문제
저는 오늘 프리셀 게임을 D(D > 0)회 플레이했습니다. 프리셀의 각 게임은 제가 이기거나 지는 두 가지 방법 중 하나로 끝납니다. 저는 수년 동안 게임을 해왔고 지금까지 총 G게임을 플레이했습니다(당연히 G ≥ D).

하루가 끝나면 게임 통계를 보고 제가 얼마나 잘 플레이했는지 확인합니다. 오늘 제가 D 게임에서 정확히 PD 퍼센트를 이겼고, 지금까지 플레이한 G 게임에서 정확히 PG 퍼센트를 이긴 것으로 나타났습니다. 기적적으로도 반올림할 필요 없이 두 백분율이 모두 정확합니다! 안타깝게도 오늘 제가 플레이한 게임(D)의 정확한 개수나 총 게임(G)의 정확한 개수는 기억나지 않습니다. 오늘 N개 이상의 게임을 플레이할 수 없었다는 것은 알고 있습니다(D ≤ N).

백분율 표시가 가능한가요, 아니면 게임 통계 계산기가 고장난 건가요?

입력
입력의 첫 번째 줄에는 테스트 케이스 수인 T가 표시됩니다. 각 줄에는 N, PD, PG의 세 정수가 포함됩니다.

한계
0 ≤ PD ≤ 100;
0 ≤ PG ≤ 100.
1 ≤ T ≤ 2000;
1 ≤ N ≤ 1015.
출력
각 테스트 케이스에 대해 “Case #x: y”를 한 줄씩 출력합니다. 여기서 x는 케이스 번호(1부터 시작)이고 y는 “Possible” 또는 “Broken” 중 하나입니다.

예제 입력 1 
3
1 100 50
10 10 100
9 80 56
예제 출력 1 
Case #1: Possible
Case #2: Broken
Case #3: Possible
힌트
In Case #3, I could have played 5 games today (D = 5) and 25 games in total (G = 25), and won 4 games today  (80% of 5) and 14 games in total (56% of 25).
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N;
        int PD, PG;
        cin >> N >> PD >> PG;
        
        if ((PG == 100 && PD != 100) || (PG == 0 && PD != 0)) {
            cout << "Case #" << t << ": Broken\n";
            continue;
        }
        
        int g = gcd(PD, 100);
        long long d = 100 / g; 
        if (d > N) {
            cout << "Case #" << t << ": Broken\n";
        } else {
            cout << "Case #" << t << ": Possible\n";
        }
    }
    return 0;
}