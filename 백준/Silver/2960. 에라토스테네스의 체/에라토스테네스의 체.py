"""
에라토스테네스의 체 다국어
 
시간 제한   메모리 제한
1 초   128 MB

문제
에라토스테네스의 체는 N보다 작거나 같은 모든 소수를 찾는 유명한 알고리즘이다.

이 알고리즘은 다음과 같다.

2부터 N까지 모든 정수를 적는다.
아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
N, K가 주어졌을 때, K번째 지우는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N, max(1, K) < N ≤ 1000)

출력
첫째 줄에 K번째 지워진 수를 출력한다.

예제 입력 1 
7 3
예제 출력 1 
6
예제 입력 2 
15 12
예제 출력 2 
7
예제 입력 3 
10 7
예제 출력 3 
9
2, 4, 6, 8, 10, 3, 9, 5, 7 순서대로 지워진다. 7번째 지워진 수는 9이다.
"""

# Answer
import sys
input = sys.stdin.readline

N, K = map(int, input().split())

sieve = [True] * (N + 1)
sieve[0] = sieve[1] = False
count = 0

for i in range(2, N + 1):
    if sieve[i]:
        for j in range(i, N + 1, i):
            if sieve[j]:
                sieve[j] = False
                count += 1
                if count == K:
                    print(j)
                    break
    if count == K:
        break