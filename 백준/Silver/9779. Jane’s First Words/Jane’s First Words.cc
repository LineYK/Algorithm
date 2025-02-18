/*
제인의 첫 마디
 
시간 제한 메모리 제한
1초 128MB	

문제
제인(제 2살짜리 아기 딸)이 이제 간단한 단어를 말하기 시작했습니다. 
“아빠"와 ‘엄마’가 가장 흔한 첫 단어입니다. 이 두 단어를 처음 듣는 것은 정말 아름답고 기억에 남습니다.

작년에 스티븐은 아기가 처음으로 아빠를 부르는 순간을 녹음하고 싶었습니다. 
그래서 스티븐은 제인의 아기 침대 근처에 마이크와 사운드 캡처 프로그램을 설치했습니다. 
이 마이크는 제인의 소리를 캡처하고 프로그램은 캡처된 단어 목록을 스티븐에게 전송했습니다. 
그는 제인이 처음으로 자신을 부르는 순간을 감지하는 프로그램을 만들었습니다: “아빠"(또는 그 변형어). 
이번에는 여러분도 비슷한 프로그램을 작성해 보세요.

입력
한 줄에 한 단어씩 주어집니다. 다음은 캡처된 소리의 목록입니다. 
각 줄에는 공백 없이 소문자 알파벳만 포함되며 최대 20자까지 입력할 수 있습니다. 입력은 EOF로 종료됩니다.

출력
각 단어/줄에 대해 해당 단어가 아래 정규식과 일치하면 “그녀가 나를 불렀다!!!”를 한 줄로 출력합니다. 
그렇지 않으면 “Cooing”을 한 줄로 출력합니다(아기의 부드러운 옹알이 소리라는 의미).

참고: 따옴표는 명확성을 위한 것입니다.

정규식(정규식) “da+dd?(i|y)”.

정규식에 익숙하지 않은 분들을 위해 설명해 드리겠습니다:

'+'는 앞의 요소 중 하나 이상을 의미합니다.
'?'는 0 또는 앞의 요소 중 하나를 의미합니다.
세로 막대 '|'는 대안을 구분합니다.
괄호는 연산자의 범위와 우선 순위를 정의하는 데 사용됩니다.

예제 입력 1 
aaaa
eeeh
auwww
dda
daaada
daddy
ouuuww
dadi
예제 출력 1 
Cooing
Cooing
Cooing
Cooing
Cooing
She called me!!!
Cooing
She called me!!!
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;

    while (cin >> s)
    {
        if (regex_match(s, regex("da+dd?(i|y)")))
            cout << "She called me!!!" << endl;
        else
            cout << "Cooing" << endl;
    }

    return 0;
}
