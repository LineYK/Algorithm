/*
단어 사다리

시간 제한	메모리 제한
1 초	128 MB

문제
단어 사다리란 퍼즐의 한 종류인데, 두 단어가 주어지면 한 단어에서 한 글자씩 바꿔서 다른 단어를 만드는 것이다. 
이 게임은 좋은 어휘력과 맞춤법이 필요하다. 그래서 정답인지 아닌지 확인하는 게 너무 지루하고 귀찮다. 

한 쌍의 단어가 단어 사다리가 되는 조건은 다음과 같다:

단어의 길이가 같고
반드시 한 글자씩 바뀌어야한다.
단어 사다리가 가능한 지 판별하는 프로그램을 작성하시오.

입력
입력이 여러 번 주어지는데, #이 입력되기 전까지를 하나의 테스트케이스로 간주한다.

각 테스트케이스는 3자 이상 20자 이하의 대문자 알파벳으로 된 단어들이 순서대로 입력된다. 
입력의 마지막 줄에는 #이 주어진다.

출력
단어 사다리가 가능하다면 'Correct'를, 아니면 'Incorrect'를 출력한다.

예제 입력 1 
BARK
BARE
#
BEAK
BRAK
BRAD
BEAD
#
BEAK
BEAD
BEND
LEND
LAND
LANE
LAKE
#
MAKE
BAKE
BONK
BONE
BANE
#
#
예제 출력 1 
Correct
Correct
Correct
Incorrect
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    bool correct = true;
    
    getline(cin, s2);
    
    while (true) {
        s1 = s2;
        getline(cin, s2);
        
        if (s2 == "#") {
            if (s1 == "#") {
                break;
            }
            else {
                if (correct) {
                    cout << "Correct" << endl;
                }
                else {
                    cout << "Incorrect" << endl;
                }
                correct = true;
                continue;
            }
        }
        
        if (s1 == "#") {
            continue;
        }
        
        if (correct) {
            if (s1.length() != s2.length()) {
                correct = false;
                continue;
            }
            
            int count = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] != s2[i]) {
                    count++;
                }
            }
            if (count != 1) {
                correct = false;
            }
        }
    }
    
    return 0;
}