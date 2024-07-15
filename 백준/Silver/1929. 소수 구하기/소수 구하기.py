"""
소수 구하기
 
시간 제한   메모리 제한   제출   정답   맞힌 사람   정답 비율
2 초   256 MB   286266   85258   60017   27.783%
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) 
M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

예제 입력 1 
3 16
예제 출력 1 
3
5
7
11
13
"""

# Answer
import sys
input = sys.stdin.readline 

def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

m, n = map(int, input().split())

for i in range(m, n+1):
    if is_prime(i):
        print(i)