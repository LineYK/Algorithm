/*
글로벌 포닉스
 
시간 제한	메모리 제한	
1 초	1024 MB
문제
모두가 알다시피, 포닉스는 인류의 삶에 기여하는 가치창출대학 포스텍을 대표하는 마스코트이다! 포닉스는 오늘도 GLOBAL하고 새로운 가치를 창출하기 위해 노력하고 있다.

컴퓨터 과학 분야에서, GLOBAL한 가치란 단언컨대 ICPC World Finals 진출이다. 포닉스는 포스텍의 ICPC World Finals 진출을 위한 응원 문구를 만들려 한다. 응원 문구는 문자열 세 개로 이루어져 있다. 포닉스의 빅데이터 연구 결과, 세 문자열이 순서와 관계없이 각각 l, k, p로 시작할 경우 포스텍은 ICPC World Finals에 진출할 수 있다. 포닉스는 이러한 응원 문구를 GLOBAL한 문구로 부르기로 했다.

포닉스가 정한 세 개의 문자열이 주어질 때, 응원 문구가 GLOBAL한지 판단하여라.

입력
첫 번째 줄부터 3개의 줄에 걸쳐 문자열 S_1, S_2, S_3이 주어진다.

모든 문자열은 알파벳 소문자 또는 숫자로 이루어진 길이 20 이하의 문자열이다.

출력
세 문자열으로 만든 응원 문구가 GLOBAL하면 GLOBAL을, 아니면 PONIX를 출력한다.

예제 입력 1 
korea
legend
postech
예제 출력 1 
GLOBAL
예제 입력 2 
turing
dijkstra
neumann
예제 출력 2 
PONIX
예제 입력 3 
leo020630
kwoncycle
petamingks
예제 출력 3 
GLOBAL
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    bool isGlobal[3] = {false, false, false};
    string keywords[3] = {"k", "l", "p"};
    string inputs[3] = {s1, s2, s3};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (inputs[i].find(keywords[j]) == 0) {
                isGlobal[j] = true;
            }
        }
    }
    
    if (isGlobal[0] && isGlobal[1] && isGlobal[2]) {
        cout << "GLOBAL\n";
    } else {
        cout << "PONIX\n";
    }

    return 0;
}
