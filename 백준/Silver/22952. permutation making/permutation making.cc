/*
permutation making

시간 제한	메모리 제한
1 초 (추가 시간 없음)	1024 MB (추가 메모리 없음)

문제
길이가 N인 순열이란, 1이상 N이하의 자연수 N개로 이루어진, 같은 수가 두 번 이상 등장하지 않는 수열을 의미한다.

여기 길이가 N인 순열 A가 있다.

이때 새로운 수열 P의 i번째 원소는 다음과 같이 정의된다.
( 1 \le i \le N) P_i = \left(\sum_{k=1}^{i}A_k\right)\ \bmod N 
P의 원소들 중 서로 다른 값이
\frac{N}{2} + 1개 이하가 되도록 하는 순열 A를 아무거나 하나 구해보자.

입력
첫째 줄에 N ( 1 \le N \le 100\,000)이 주어진다.

출력
A_1부터 A_N까지의 원소를 공백을 기준으로 출력한다.

조건을 만족하는 순열 A가 항상 존재한다.

예제 입력 1
5
예제 출력 1
3 2 4 5 1
수열 P의 원소들 중 서로 다른 값은 0,3,4로 3종류가 있고, 총 3개로
 \frac{N}{2} + 1개 이하이다.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    cout << N << " ";
    for (long long i = 1; i < N / 2; i++)
    {
        cout << i << " " << N - i << " ";
    }

    if (N == 1)
        return 0;

    cout << N / 2 << " ";

    if (N % 2 == 1)
        cout << N / 2 + 1;

    return 0;
}