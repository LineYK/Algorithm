/*
가장 작은 계산 값
 
시간 제한 메모리 제한 제출
1초 (추가 시간 없음) 1024MB

문제

세 개의 정수와 산술 연산자(+, -, *, /)가 주어졌을 때, 
초기 정수의 순서를 바꾸지 않고 가능한 가장 작은 음수가 아닌 정수를 구합니다. 
연산자의 순서는 일반적인 우선순위 없이 왼쪽에서 오른쪽으로만 적용됩니다. 
참고: 정수 나누기는 나머지가 0인 경우에만 괜찮습니다.
예를 들어 9/3은 괜찮습니다, 10/3은 안 됩니다.

예를 들어

2, 3 및 5의 경우, 
답은 0 (2+3-5)

9, 9 및 9의 경우, 
답은 0 (9 - 9 / 9)

5, 7 및 3의 경우, 답은 다음과 같습니다. 
1 (5-7+3)

세 개의 정수가 주어졌을 때, 
주어진 연산자를 숫자 사이에 배치하여 계산할 수 있는 가장 작은 음이 아닌 결과를 구합니다. 
연산자는 숫자 사이에만 배치할 수 있으며, 앞에는 배치할 수 없습니다(단항 연산자가 아님). 
연산자는 각 숫자 쌍 사이에 배치해야 하며, 숫자를 연결할 수 없습니다.

입력
한 줄의 입력에는 세 개의 정수가 포함되며, 모두 범위는 1에서 1,000.

출력
산술 연산자를 적용한 가능한 가장 작은 음수가 아닌 값인 단일 정수를 출력합니다.

예제 입력 1 
2 3 5
예제 출력 1 
0
예제 입력 2 
9 9 9
예제 출력 2 
0
예제 입력 3 
5 7 3
예제 출력 3 
1
*/

#include <bits/stdc++.h>

using namespace std;

char op[4] = {'+', '-', '*', '/'};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    unsigned int result = 0xFFFFFFFF;

    auto apply_op = [](int x, int y, char op) -> unsigned int {
        switch (op) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            case '/': return (y != 0 && x % y == 0) ? x / y : 0xFFFFFFFF;
            default: return 0xFFFFFFFF;
        }
    };

    for (char op1 : op) {
        for (char op2 : op) {
            unsigned int temp = apply_op(a, b, op1);
            if (temp == 0xFFFFFFFF) continue;
            temp = apply_op(temp, c, op2);
            if (temp == 0xFFFFFFFF) continue;
            
            result = min(result, temp);
        }
    }

    cout << result << "\n"; 
    return 0;
}
