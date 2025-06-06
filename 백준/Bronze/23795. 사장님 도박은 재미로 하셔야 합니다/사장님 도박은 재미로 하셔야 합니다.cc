/*
사장님 도박은 재미로 하셔야 합니다
 
시간 제한	메모리 제한	
1 초	512 MB

문제
영국에는 스티븐 제라드라는 전설의 야바위꾼이 있다. 영국으로 여행을 떠난 윤성이는 스티븐 제라드를 만나게 되었다.

이 전설의 야바위꾼이 진행하는 야바위는 널리 알려진 방식과 동일하다. 
\(3\)개의 컵과 하나의 공을 사용해 임의의 한 컵에 공을 넣고 무작위로 컵들의 위치를 바꾼다. 야바위꾼이 정한 특정 순간에 위치 변경을 멈추게 되는데 그 순간 관객이 공의 위치를 찾으면 돈을 받을 수 있다. 스티븐 제라드가 공의 위치를 찾았을 때 베팅한 돈의 
\(10\)배를 주겠다 제안하자 윤성이는 솔깃해져 게임에 참여하게 되었다.

전설의 야바위꾼의 빠른 손놀림에 윤성이는 단 한번도 공의 위치를 찾지 못했고, 결국 윤성이는 배팅을 계속하다 지쳐 자리를 뜨게 되었다. 윤성이가 자리를 뜨기 전까지 잃은 돈을 계산하는 프로그램을 작성하자.

입력
윤성이가 판마다 배팅한 양의 정수 형태의 돈이 한 줄에 하나씩 입력된다. 입력의 맨 마지막줄에는 윤성이가 자리를 뜨는 순간을 의미하는 수인 -1이 들어온다.

입력된 값은 
\(2,000\)개 미만이고, 윤성이가 베팅한 돈의 합은 
\(2,147,483,647\)을 넘지 않는다.

출력
윤성이가 도박판에서 버린 돈의 총 합을 출력한다.

예제 입력 1 
1
2
3
4
5
6
7
8
9
10
-1
예제 출력 1 
55
*/

#include <bits/stdc++.h>
using namespace std;
static const long long INF = (1LL<<60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sum = 0;
    while(true){
        int x;
        cin >> x;
        if(x == -1) break;
        sum += x;
    }
    cout << sum << endl;
    
    return 0;
}