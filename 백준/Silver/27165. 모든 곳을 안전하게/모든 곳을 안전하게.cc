/*
모든 곳을 안전하게
 
시간 제한	메모리 제한	
1 초	1024 MB

문제
《백개먼》은 주사위 두 개를 던져서 나온 눈의 수만큼 말을 선택하여 정해진 방향으로 이동시키는 게임입니다. 말을 이동할 수 있다면 반드시 이동해야 하며, 두 주사위의 눈이 같다면 각 주사위의 눈을 두 번씩 총 4번 사용해야 합니다. 예를 들어 주사위의 눈이 4, 5라면, 하나의 말을 9칸 이동하거나, 두 개의 말을 각각 4칸, 5칸 이동할 수 있습니다. 그리고 주사위의 눈이 3, 3이라면, 3칸 이동하는 것을 총 4번 진행해야 합니다.

말을 이동할 때, 상대편 말이 두 개 이상 있는 칸으로는 이동할 수 없지만, 상대편 말이 정확히 1개 있는 칸으로 이동하는 것은 가능합니다. 이때 상대편의 말은 처음부터 다시 이동해야 합니다. 따라서 본인의 말이 잡히지 않도록, 본인의 말이 있는 모든 칸에 두 개 이상의 말이 있는 상태를 유지하는 것이 이 게임의 간단한 전략 중 하나입니다. 이러한 상태를 안전한 상태라 합시다. 안전한 상태는 상대편의 말이 없더라도 정의될 수 있습니다.

0번부터 n번까지 왼쪽부터 순서대로 번호가 매겨진 n+1개의 칸이 있고 주사위의 눈이 1부터 n까지 있는 변형된 게임판을 생각해 봅시다. i번 칸에 놓여있는 말 하나에 주사위 눈 x를 사용하면 i+x번 칸으로 이동하게 됩니다. 단, i+x>n인 경우에는 이동할 수 없습니다.

실버는 백개먼의 고수가 되기 위해 안전한 상태를 만드는 연습을 하고 있습니다. 현재 게임판에는 실버의 검은 말만 놓여있는 상태입니다. 성질이 급한 실버는 주사위의 눈을 하나만 남기고 모두 이동했습니다. 현재 0번 칸에는 1개 이상의 말이 있습니다. 마지막 남은 주사위의 눈을 어떻게 사용해야 안전한 상태를 만들 수 있는지 구해봅시다.

입력
첫 번째 줄에 정수 n이 주어집니다.

두 번째 줄에 0번부터 n번까지 각 칸에 있는 말의 개수 a_0, a_1, \cdots, a_n이 공백으로 구분되어 주어집니다.

세 번째 줄에 남은 주사위의 눈을 나타내는 정수 x가 주어집니다.

출력
만약 어떻게 이동하더라도 안전한 상태를 만들 수 없다면 첫 번째 줄에 NO를 출력합니다.

안전한 상태를 만들 수 있다면 첫 번째 줄에 YES를 출력합니다. 다음 줄에 이동할 말의 시작 칸과 도착 칸을 공백으로 구분하여 출력합니다. 가능한 이동이 여러 가지라면 아무거나 한 가지만 출력합니다.

제한
1 \le n \le 1\,000\,000
모든 0 \le i \le n에 대해 0 \le a_i \le 10
1 \le a_0
1 \le x \le n
예제 입력 1 
6
4 0 1 0 0 2 1
4
예제 출력 1 
YES
2 6


예제 입력 2 
6
4 0 1 0 0 2 1
5
예제 출력 2 
NO
예제 입력 3 
3
2 0 0 2
3
예제 출력 3 
NO
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    for (int i = 0; i <= n; i++){
        cin >> a[i];
    }
    
    int x;
    cin >> x;
    
    vector<int> unsafeIdx;
    for (int i = 0; i <= n; i++){
        if(a[i] == 1)
            unsafeIdx.push_back(i);
    }
    
    if(unsafeIdx.size() > 2){
        cout << "NO" << "\n";
        return 0;
    }
    
    int from = -1, to = -1;
    
    if(unsafeIdx.size() == 2){
        int u = unsafeIdx[0], v = unsafeIdx[1];
        if(v - u == x){
            from = u;
            to = v;
        }
    }

    else if(unsafeIdx.size() == 1){
        int u = unsafeIdx[0];

        if(u + x <= n && a[u+x] >= 1){ 
            from = u;
            to = u + x;
        }

        else if(u - x >= 0 && (a[u-x] == 1 || a[u-x] >= 3)){
            from = u - x;
            to = u;
        }
    }
    else {
        for (int i = 0; i <= n - x; i++){
            if(a[i] >= 3 && a[i+x] >= 1){
                from = i;
                to = i + x;
                break;
            }
        }
    }
    
    
    if(from == -1 || to == -1){
        cout << "NO" << "\n";
        return 0;
    }
    
    vector<int> finalState = a;
    finalState[from]--;
    finalState[to]++;  
    
    bool safe = true;
    for (int i = 0; i <= n; i++){
        if(finalState[i] > 0 && finalState[i] < 2){
            safe = false;
            break;
        }
    }
    
    if(safe){
        cout << "YES" << "\n";
        cout << from << " " << to << "\n";
    } else {
        cout << "NO" << "\n";
    }
    
    return 0;
}
