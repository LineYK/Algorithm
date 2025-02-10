/*
sqrt log sin 다국어
 
시간 제한	메모리 제한
1 초	128 MB

문제
도현이는 수학 숙제를 하고 있다. 문제는 다음과 같다.

다음과 같이 재귀적으로 정의된 수열이 있다.

 
\(x_0 = 1\) 

 
\(x_i = x_{\lfloor i - \sqrt{i} \rfloor} + x_{\lfloor \ln{(i)} \rfloor} + x_{\lfloor i \sin^{2}{(i)} \rfloor}\) 

이때, 
\(x_{1000000}\)을 구하시오.

 
\(i\)가 주어졌을 때, 
\(x_i\)를 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있으며, 한 줄에 하나씩 주어진다.

각 줄에는 
\(i\)가 주어지며, 이 수는 0보다 작지 않고, 백만보다 크지 않다.

입력의 마지막 줄에는 -1이 주어지며, 이 수는 입력의 마지막을 나타내는 수이다.

출력
입력으로 주어진 
\(i\)마다 
\(x_i\)를 1000000로 나눈 나머지를 출력한다.

예제 입력 1 
0
-1
예제 출력 1 
1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> dp(1000001, 1);

    for (int i = 1; i <= 1000000; i++) {
        dp[i] = dp[(int)(i - sqrt(i))] + dp[(int)log(i)] + dp[(int)(i * sin(i) * sin(i))];
        dp[i] %= 1000000;
    }

    while (1) {
        cin >> n;
        if (n == -1) break;
        cout << dp[n] << '\n';
    }
    
    return 0;
}