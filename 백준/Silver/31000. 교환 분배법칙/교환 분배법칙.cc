/*
교환 분배법칙
 
시간 제한	메모리 제한
1 초	1024 MB	

문제
최근 덧셈과 곱셈을 공부하던 즈티는 분배법칙이라는 것을 배웠다. 덧셈과 곱셈에 대한 분배법칙은 다음이 항상 성립함을 의미한다.

임의의 세 실수 a, b, c에 대해 a \times (b + c) = (a \times b) + (a \times c).
여기서 즈티는 덧셈과 곱셈 기호의 위치가 바뀐 다음과 같은 식도 성립하지는 않는지 의문이 생겼다.

임의의 세 실수 a, b, c에 대해 a + (b \times c) = (a + b) \times (a + c).
즈티는 아직 어려서 큰 수를 다루지 못한다. 그래서 a, b, c가 절댓값이 N을 넘지 않는 정수인 경우에만 위 식을 계산할 수 있다. 아직 의문이 풀리지 않은 즈티를 위해, 주어진 조건에서 기호가 교환된 분배법칙을 만족하는 (a, b, c) 정수 쌍의 개수를 구해주자.

입력
첫째 줄에 a, b, c의 절댓값이 넘지 못하는 범위 N이 주어진다. (1 \leq N \leq 3\,000) 

출력
교환 분배법칙을 만족하는 (a, b, c) 정수 쌍의 개수를 출력한다.

예제 입력 1 
1
예제 출력 1 
13
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    long long ans = 7*N*N + 5*N + 1;
    cout << ans << "\n";
    return 0;
}