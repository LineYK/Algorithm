/*
품질검사
 
시간 제한	메모리 제한
1 초	128 MB	
문제
공장이는 기계 부품을 만드는 공장에서 품질 관리 책임자를 맡고 있다. 이 공장에서는 A, B, C 부품을 생산하는데, 매일 각 부품을 a, b, c개씩 생산한다. 그리고 부품 각각에는 1~a, a+1~a+b, a+b+1~a+b+c의 번호가 붙어있다. 그러나 모든 부품이 완벽하게 만들어지는 것은 아니라서 일부 부품은 결함이 있을 수도 있다. 이에 공장에서는 매일 부품 검사를 시행하는데 그 과정은 다음과 같다.

A, B, C 부품을 각각 하나씩 가져와 연결하고 작동시킨다.
모든 부품이 정상인 경우 기계가 정상 작동하여 "합격"
부품이 하나라도 고장 난 경우 기계가 오작동하여 "불합격"
이 과정은 매우 정밀하므로 고장 난 부품이 섞여 있는데 우연히 제대로 작동하는 경우는 없다. 그러나 게으른 공장이는 검사 횟수가 충분하지 않더라도 검사를 끝내기도 한다. 공장이가 잘리지 않도록 검사 결과 목록이 주어졌을 때 모든 부품을 다음 세 가지 경우 중 어떤 것인지 분류해주도록 하자.

정상
고장
알 수 없음
입력
1번째 줄에 전원의 개수 a, 모터의 개수 b, 케이블의 개수 c가 공백으로 구분되어 주어진다. (1 ≦ a, b, c ≦ 100)

2번째 줄에 검사 횟수 N이 주어진다. (1 ≦ N ≦ 1000)

이어서 N개의 줄에 검사 결과가 주어진다. 전원 번호 i, 모터 번호 j, 케이블 번호 k, 검사 결과 r이 공백으로 구분되어 주어지며, r=1인 경우 합격, r=0인 경우 불합격이다.

출력
a+b+c개의 줄에 걸쳐 부품이 어느 분류인지 출력한다.

부품 i가 고장인 경우 0
부품 i가 정상인 경우 1
부품 i가 고장인지 정상인지 알 수 없는 경우 2
예제 입력 1 
2 2 2
4
2 4 5 0
2 3 6 0
1 4 5 0
2 3 5 1
예제 출력 1 
2
1
1
0
1
0
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, N;
    cin >> a >> b >> c >> N;
    int P = a + b + c;

    vector<int> status(P+1, 2);

    struct Test { int x, y, z, r; };
    vector<Test> tests(N);

    for(int i = 0; i < N; i++){
        auto &t = tests[i];
        cin >> t.x >> t.y >> t.z >> t.r;
        if(t.r == 1){
            status[t.x] = status[t.y] = status[t.z] = 1;
        }
    }

    vector<Test> failTests;
    for(auto &t : tests){
        if(t.r == 0) failTests.push_back(t);
    }

    bool changed = true;
    while(changed){
        changed = false;
        for(auto &t : failTests){
            int x = t.x, y = t.y, z = t.z;
            int goodCnt = 0, badCnt = 0;
            int unknownIdx = -1;
            for(auto v : {x,y,z}){
                if(status[v] == 1) goodCnt++;
                else if(status[v] == 0) badCnt++;
                else unknownIdx = v;
            }
            if(badCnt > 0) continue;
            if(goodCnt == 2 && unknownIdx != -1){
                status[unknownIdx] = 0;
                changed = true;
            }
        }
    }

    for(int i = 1; i <= P; i++){
        cout << status[i] << "\n";
    }
    return 0;
}
