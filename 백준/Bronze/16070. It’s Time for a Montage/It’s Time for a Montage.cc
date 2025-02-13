/*
몽타주 시간입니다
 
시간 제한 메모리 제한
2초 512MB	

문제
좋아하는 액션 TV 쇼의 영웅들이 악당과의 마지막 대결을 준비하고 있습니다. 
기본적으로 서로 싸울 두 명의 라이벌, 
즉 우주를 구하려는 매우 중요한 주인공과 우주를 파괴하려는 똑같이 중요한 주인공 빌런이 있습니다. 
그러나 수많은 재귀적 스핀오프를 통해 이 둘은 약간 덜 중요한 조력자(영웅과 악당 자체가 라이벌인 조력자)를 가질 수 있고, 
그 조력자 역시 자신의 (덜 중요한) 조력자를 가질 수 있는 식으로 반복될 수 있습니다. 
영웅과 악당의 수는 같으며, 각 라이벌 쌍에는 최대 한 명의 조력자 쌍이 있다는 점에 유의하세요.

처음에는 모든 캐릭터가 라이벌과 싸우게 되며, 누가 더 높은 파워 레벨을 가졌는지에 따라 승자가 결정됩니다. 
영웅과 해당 악당의 파워 레벨이 같은 경우, 
승리한 조력자가 일종의 동점 상황에서 도움을 줄 수 있으므로 조력자의 전투에 따라 전투가 결정됩니다. 
(같은 파워 레벨의 상대에게 조수가 없는 경우, 영웅 캐릭터가 무작위 행인의 도움을 받아 승리합니다.) 
하지만 어느 한 쪽이 전투에서 승리해도 조수가 할 수 있는 일은 없습니다. 
제작진은 캐릭터가 덜 중요한 캐릭터에게 패배하면 
일부 팬들이 화를 낼 수 있다고 판단하여 파워 레벨과 상관없이 패배할 수 있도록 했습니다.

라이벌 간의 전투(및 동점자 발생 가능성)가 끝나면 가장 중요한 캐릭터가 나머지 상대방을 물리치고 
우주의 운명을 결정하게 됩니다. 다행히도 영웅들은 힘들고 혹독한 훈련을 통해 승리를 보장할 수 있습니다. 
훈련에 소비하는 하루마다 각 영웅의 파워 레벨은 1씩 증가하지만 악당의 파워 레벨은 일정하게 유지됩니다.

하지만 여러분은 이미 이 모든 것을 알고 있습니다. 
여러분을 괴롭히는 문제는 훈련이 얼마나 오래 걸릴지입니다.

입력
입력은 다음과 같이 구성됩니다:

라이벌 쌍의 수를 나타내는 정수 n(1 ≤ n ≤ 1,000)이 포함된 한 줄.
정수 n이 포함된 한 줄 h1, . . . , hn(각 i마다 1 ≤ hi ≤ 1,000)의 정수로 이루어진 한 줄, 
i번째 가장 중요한 영웅의 파워 레벨을 나타내는 i번째 값입니다.
n 개의 정수가 있는 한 줄 v1, . . . , vn (각 i마다 1 ≤ vi ≤ 1,000), 
i번째 가장 중요한 악당의 파워 레벨을 나타내는 i번째 값입니다.

출력
영웅이 자신의 편이 승리하기 위해 훈련에 소비해야 하는 최소 일수를 정수로 출력합니다.

예제 입력 1 
4
5 3 1 1
8 6 9 1
예제 출력 1 
4
예제 입력 2 
1
2
1
예제 출력 2 
0
예제 입력 3 
2
4 2
7 5
예제 출력 3 
3
*/

#include <bits/stdc++.h>
using namespace std;

bool canWin(vector<int>& hero, vector<int>& villain, int days, int idx, int n) {
    if (idx == n) return true;  
    
    int currentPower = hero[idx] + days;  
    
    if (currentPower > villain[idx]) return true;
    
    if (currentPower < villain[idx]) return false;
    
    if (currentPower == villain[idx]) {
        if (idx == n-1 || canWin(hero, villain, days, idx+1, n)) {
            return true;
        }
        return false;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> hero(n), villain(n);
    
    for (int i = 0; i < n; i++) cin >> hero[i];
    for (int i = 0; i < n; i++) cin >> villain[i];

    int left = 0, right = 1000;
    int ans = right;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (canWin(hero, villain, mid, 0, n)) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}