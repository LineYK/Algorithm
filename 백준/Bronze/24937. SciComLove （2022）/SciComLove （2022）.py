"""
SciComLove (2022) 서브태스크
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	679	426	373	64.533%
문제
귀여운 아기 리프가 가장 좋아하는 문자열은 "SciComLove"(따옴표 제외)입니다. 귀여운 아기 리프는 아래 과정을 반복하며 문자열을 가지고 놀고 있습니다.

문자열의 가장 첫 문자를 떼어낸 뒤, 문자열의 맨 뒤에 붙입니다.
귀여운 아기 리프가 이 과정을 
$N$번 반복한 뒤, 문자열의 최종 상태를 출력하세요.

입력
정수 
$N$이 주어집니다.

출력
문제의 답을 출력합니다. 대소문자에 주의하세요.

제한
0  N  10^9

예제 입력 1 
3
예제 출력 1 
ComLoveSci
예제 입력 2 
15
예제 출력 2 
mLoveSciCo
"""

# Answer
import sys
input = sys.stdin.readline

N = int(input())
string = "SciComLove"

N %= len(string)
print(string[N:] + string[:N])