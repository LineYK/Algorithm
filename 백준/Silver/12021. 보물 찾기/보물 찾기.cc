/*
물 찾기 스페셜 저지
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	707	336	284	51.920%
문제
희현이는 학교를 가다가 보물 지도를 주웠다. 보물 지도에 써져 있는 내용은 다음과 같았다.

연세대학교 정문의 좌표를 (0, 0)이라 하자.
 
\(x_0 = a\), 
\(y_0 = b\)이다. (
\(0 < b \le a\))
 
 
\(x_{n+1} = \frac{(x_n + y_n)}{2}\), 
 
\(y_{n+1} = 2\frac{x_ny_n}{x_n+y_n}\) 
계속 쫓아가다 보면 보물은 나오기 마련!
희현이를 도와 보물이 있는 위치를 구하자.

입력
첫째 줄에 양의 정수 
\(a\)와 
\(b\)가 주어진다. (
\(0 < b \le a \le 10^{18}\))

출력
첫째 줄에 보물이 있는 좌표를 출력하자. 상대/절대 오차는 10-6까지 허용한다.

예제 입력 1 
1 1
예제 출력 1 
1.000 1.000
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double a, b;
    cin >> a >> b;

    double x = a, y = b;

    for (int i = 0; i < 100000; i++)
    {
        double nx = (x + y) / 2;
        double ny = 2 * x * y / (x + y);

        x = nx;
        y = ny;
    }

    cout << fixed;
    cout.precision(3);
    cout << x << " " << y;

    return 0;
}
