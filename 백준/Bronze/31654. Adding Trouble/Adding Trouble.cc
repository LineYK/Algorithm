/*
Adding Trouble
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	1024 MB	1888	1531	1472	82.743%
문제
Your friend Bob is really bad at adding numbers, and he’d like some help to make sure he’s doing it correctly! Can you help Bob make sure he is adding correctly? Given 3 integers 
$A$, 
$B$, 
$C$, make sure that 
$A + B = C$, and that Bob indeed added 
$A$ and 
$B$ correctly.

입력
The input consists of a single line with 3 integers 
$A, B, C$ where 
$-10^9 \le A, B, C \le 10^9$.

출력
Output either correct! if 
$A + B = C$, or wrong! if 
$A + B \ne C$.

예제 입력 1 
2 3 5
예제 출력 1 
correct!
예제 입력 2 
1 1 3
예제 출력 2 
wrong!
예제 입력 3 
-1 1 0
예제 출력 3 
correct!
*/

#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    if (A + B == C)
      cout << "correct!";
    else
      cout << "wrong!";
    
    return 0;
}