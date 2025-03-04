/*
RPG 마스터 오명진
 
시간 제한	메모리 제한
0.3 초 (추가 시간 없음)	512 MB

문제
소프트웨어학부에 재학중인 명진이는 요즘 방역 수칙을 지키기 위해 게임을 하고있다. 그러나 모든 RPG를 다 클리어해버린 명진이는 자신이 직접 RPG를 만들기로 결심한다. 게임은 용사와 마왕의 전투로 이루어진다. 용사와 마왕은 각각 공격력(ATK)과 체력(HP)을 가지고있다. 또한 게임이 단조로워지는 것을 방지하기 위하여, 명진이는 마왕에게 스킬을 선물했다. 마왕의 체력이 1이상 P 이하로 떨어지게 되면 1번에 한해 S만큼 체력을 회복한다! 명진이의 게임은 다음과 같이 진행된다.

용사의 공격력만큼 마왕의 체력을 깎습니다.
마왕의 체력이 0 이하이면 용사가 승리하고 게임이 종료됩니다.
마왕의 공격력만큼 용사의 체력을 깎습니다.
용사의 체력이 0 이하이면 용사가 패배하고 게임이 종료됩니다.
마왕의 체력이 1 이상 P 이하일 경우 S만큼의 체력을 회복합니다.
게임이 종료 될 때까지 (1~5)의 과정을 반복합니다.
명진이는 자신이 만든 게임의 난이도를 테스트해보고 싶어졌다. 게임을 만드는데 지친 명진이를 도와 용사가 마왕을 이길 수 있을 지 알려주는 프로그램을 만들어주자!

입력
첫째 줄에 HP용사와 ATK용사, HP마왕, ATK마왕 이 주어진다.

용사와 마왕의 체력과 공격력은 231 -1 이하의 자연수이다.

둘째 줄에 마왕의 스킬 발동 시점 P (1 ≤ P < HP마왕) 과 회복량 S(1 ≤ S ≤ HP마왕)이 주어진다.

출력
첫 째 줄에 용사의 승리 여부를 출력한다.

용사가 승리하면 "Victory!", 패배하면 "gg"를 출력한다.

예제 입력 1 
10 5 100 1
1 1
예제 출력 1 
gg
9번째 공방 이후 용사는 1, 마왕은 50의 체력이 남는다.

다음 마왕의 공격에 용사가 사망하게 된다.

예제 입력 2 
10 7 50 1
30 10
예제 출력 2 
Victory!
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll heroHP, heroATK, demonHP, demonATK;
    cin >> heroHP >> heroATK >> demonHP >> demonATK;
    
    ll P, S;
    cin >> P >> S;
    
    ll r = (demonHP + heroATK - 1) / heroATK; 

    ll i0 = (demonHP > P ? (demonHP - P + heroATK - 1) / heroATK : 1);
    
    bool recovery = false;
    if(i0 < r) {
        ll hpAfterAttack = demonHP - i0 * heroATK;
        if(hpAfterAttack >= 1 && hpAfterAttack <= P) {
            recovery = true;
        }
    }
    
    bool win = false;
    
    if(!recovery){
        ll damageTaken = demonATK * (r - 1);
        if(heroHP > damageTaken) win = true;
    } else {
        ll demonHPAfterRecovery = demonHP - i0 * heroATK + S;
        ll r2 = (demonHPAfterRecovery + heroATK - 1) / heroATK;
        ll damageTaken = demonATK * (i0 + r2 - 1);
        if(heroHP > damageTaken) win = true;
    }
    
    cout << (win ? "Victory!" : "gg") << "\n";
    
    return 0;
}
