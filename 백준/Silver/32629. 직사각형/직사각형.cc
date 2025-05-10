/*
직사각형

시간 제한	메모리 제한
1 초 (추가 시간 없음)	1024 MB (추가 메모리 없음)

문제
크기가 무한한 정사각 격자가 있다. 이 격자 위에 N개의 1 \times 1 정사각형들을 각각 서로 다른 칸에 배치하려고 한다.

다음 조건들을 만족하는 도형 중 둘레가 최소인 도형을 최소 경계 직사각형이라고 하자.

도형은 모든 변이 격자와 평행한 직사각형이다.
도형은 배치한 정사각형들을 모두 포함한다.
 N개의 정사각형을 배치하는 방법들 중 최소 경계 직사각형의 둘레가 가장 짧은 경우는 어떤 경우일까?

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. (1 \le T \le 2 \times 10^5)

두 번째 줄부터 T개의 줄에 걸쳐 각 줄에 하나씩, 배치하고자 하는 정사각형의 개수 N이 주어진다. (1 \le N \le 10^9)

출력
각 테스트 케이스마다 최소 경계 직사각형의 둘레가 가장 짧은 경우의 둘레를 출력한다.

예제 입력 1
3
9
14
33
예제 출력 1
12
16
24
아래의 그림은 예제의 테스트 케이스를 나타낸다.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;

        ll a = sqrt((long double)N);
        while (a + 1 <= N / (a + 1)) ++a;
        while (a * a > N) --a;
        ll h1 = (N + a - 1) / a;
        ll s1 = a + h1;
        ll b = a + 1;
        ll h2 = (N + b - 1) / b;
        ll s2 = b + h2;
        ll best = min(s1, s2);
        ll perimeter = 2 * best;
        cout << perimeter << '\n';
    }
    return 0;
}
