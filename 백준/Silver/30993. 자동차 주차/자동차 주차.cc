/*
자동차 주차
 
시간 제한	메모리 제한
1 초	1024 MB
문제
같은 차종의 빨간색 자동차 A대, 초록색 자동차 B대, 파란색 자동차 C대를 
N칸의 주차장에 1대씩 주차하려고 한다.

모든 자동차를 한 칸에 한 대씩 주차할 수 있는 경우의 수를 구하라.

입력
첫 번째 줄에 양의 정수 N, A, B, C가 공백으로 구분되어 주어진다.

출력
첫 번째 줄에 정답을 출력한다.

제한
 
A+B+C = N <= 15
예제 입력 1 
7 2 2 3
예제 출력 1 
210
예제 입력 2 
8 1 2 5
예제 출력 2 
168
*/

#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    long long dp[16] = {0, };

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1] * i;
        }
    }

    long long ans = dp[n] / (dp[a] * dp[b] * dp[c]);
   
    cout << ans << '\n';

    return 0;
}