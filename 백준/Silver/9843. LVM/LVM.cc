/*
LVM
 
시간 제한 메모리 제한
2초 512MB

문제
롬복이라는 새로운 프로그래밍 언어용 가상 머신을 설계하고 있습니다. 
롬복 가상 머신(LVM)은 어셈블러와 유사한 머신 코드를 실행합니다. 스택과 단일 레지스터에서 작동합니다.

자세히 설명하면 다음과 같이 작동합니다:

PUSH x: 이 명령어는 주어진 정수를 스택에 밀어 넣습니다. 
예를 들어 스택이 다음과 같다면
스택이 다음과 같고 머신이 PUSH -11 명령을 실행하면 스택은 나중에 다음과 같이 보입니다:

STORE: 이 명령어는 스택에서 최상위 정수를 가져와 레지스터에 저장합니다. 
예를 들어 스택이 다음과 같이 표시되면
레지스터에 정수가 포함되어 있고 머신이 STORE 명령을 실행하면 스택은 나중에 다음과 같이 보입니다:
레지스터에는 정수 3이 포함됩니다.

LOAD: 이 명령어는 레지스터의 내용을 복사하여 스택에 푸시합니다. 
예를 들어 레지스터에 정수 6이 포함되어 있으면 스택은 다음과 같이 보입니다.
머신이 LOAD 명령을 실행하면 스택은 다음과 같이 보입니다.
그리고 레지스터에는 여전히 정수 6이 포함됩니다.

PLUS: 이 명령어는 스택에서 맨 위에 있는 두 정수를 가져와 더한 다음 결과 정수를 다시 스택에 밀어 넣습니다. 
예를 들어 스택이 다음과 같다면
스택이 다음과 같고 머신이 명령어 PLUS를 실행하면 스택은 이후 다음과 같이 보입니다:

TIMES: 이 명령어는 스택에서 맨 위에 있는 두 정수를 가져와 곱한 다음 결과 정수를 다시 스택에 밀어 넣습니다. 
예를 들어 스택이 다음과 같다면
명령어를 실행하면 스택은 다음과 같이 보입니다:

IFZERO n: 이 명령어는 스택에서 최상위 정수를 제거하고 0과 같은지 확인합니다. 
0이면 n번째 명령어로 이동합니다(0에서 카운트 시작). 
그렇지 않은 경우 기계는 평소와 같이 다음 명령어를 계속 수행합니다. 아래 예시를 참조하세요.

DONE: 마지막으로 DONE 명령어는 스택 위에 정수를 출력하고 다음 명령어와 관계없이 프로그램을 종료합니다.

계산은 첫 번째 명령어부터 시작됩니다. 처음에는 스택이 비어 있고 레지스터에 숫자 0이 들어 있습니다.

입력
입력의 첫 번째 줄에는 프로그램의 명령어 수를 나타내는 2에서 1000 사이의 정수 n이 포함됩니다. 
다음 n줄은 프로그램 명령어를 포함합니다. 인수는 앞의 명령어와 공백 문자로 구분됩니다.

출력
출력은 실행 중에 발생하는 첫 번째 DONE 명령어의 결과인 단일 정수로 구성됩니다.

예제 입력 1 
14
PUSH 5
STORE
LOAD
LOAD
PUSH -1
PLUS
STORE
LOAD
IFZERO 13
LOAD
TIMES
PUSH 0
IFZERO 3
DONE
예제 출력 1 
120

힌트
0: PUSH 5
1: STORE
2: LOAD
3: LOAD
4: PUSH -1
5: PLUS
6: STORE
7: LOAD
8: IFZERO 13
9: LOAD
10: TIMES
11: PUSH 0
12: IFZERO 3
13: DONE

줄 번호는 설명을 위해 추가한 것으로, 프로그램의 일부가 아닙니다. 
처음 8개의 명령어를 실행한 후 스택은 다음과 같이 보입니다:

레지스터에는 정수 4가 포함됩니다. 다음 명령어 IFZERO 13는 스택에서 정수 4를 제거합니다. 
4는 0과 같지 않으므로 다음에 LOAD, TIMES 및 PUSH 0 명령어가 실행되어 스택이 생성됩니다:

다음 명령어 IFZERO 3은 0이 0과 같으므로 스택에서 0을 제거하고 
두 번째 LOAD 명령어(주소 3)로 이동합니다. 
결국 이 프로그램은 5 × 4 × 3 × 2 × 1을 계산하여 결과 정수 120을 출력합니다.

주어진 프로그램이 정확하다고 가정할 수 있습니다. 
무한 루프가 없으며, 프로그램은 빈 스택에서 정수를 제거하려고 시도하지 않습니다. 
스택이 100보다 커지지 않고, PUSH의 인수가 -10000보다 작지 않고 10000보다 크지 않은 정수이며, 
IFZERO의 인수가 0보다 작지 않고 1000보다 크지 않은 정수라고 가정할 수 있습니다.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, v[i]);
    }

    stack<int> s;
    int reg = 0;

    for (int i = 0; i < n; i++)
    {
        string cmd = v[i];
        stringstream ss(cmd);
        string inst;
        ss >> inst;

        if (inst == "PUSH")
        {
            int x;
            ss >> x;
            s.push(x);
        }
        else if (inst == "STORE")
        {
            if (!s.empty())
            {
                reg = s.top();
                s.pop();
            }
        }
        else if (inst == "LOAD")
        {
            s.push(reg);
        }
        else if (inst == "PLUS")
        {
            if (s.size() >= 2)
            {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a + b);
            }
        }
        else if (inst == "TIMES")
        {
            if (s.size() >= 2)
            {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a * b);
            }
        }
        else if (inst == "IFZERO")
        {
            int x;
            ss >> x;
            if (!s.empty() && s.top() == 0)
            {
                i = x - 1;
            }
            if (!s.empty())
            {
                s.pop();
            }
        }
        else if (inst == "DONE")
        {
            if (!s.empty())
            {
                cout << s.top() << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
