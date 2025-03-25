/*
너 그리고 나 (NAVILLERA)

시간 제한	메모리 제한
1 초	1024 MB

문제
나비처럼 날아 나나나 나빌레라

바람아 바람아 불어라

훨훨 날아가 너에게로 다가갈 수 있도록

하얀 진심을 담아

나는 너를 향해 나비처럼 날아가고자 한다. 나는 좌표평면에서 (0,0) 지점에 있으며, 너는 (X,Y)에 있다.

나비처럼 날아가기 위해, 나는 0번 이상의 ”날갯짓”을 할 수 있다.

위치 (a,b)에서 한 번의 ”날갯짓”을 하면 나는 (x-a)^2+(y-b)^2=c^2인 (x,y)로 이동할 수 있다.

너의 위치인 (X,Y)에 도달하기 위한 날갯짓의 최소 횟수를 구하여라.

입력
첫째 줄에 X,Y,c가 주어진다.

출력
첫째 줄에 날갯짓의 최소 횟수를 출력하라.

제한
 -10^4\leq X,Y\leq 10^4 
 1\leq c\leq 10^{4} 
입력으로 주어지는 모든 수는 정수이다.
예제 입력 1
4 3 4
예제 출력 1
2
예제 입력 2
1 1 10
예제 출력 2
2
예제 입력 3
3 4 5
예제 출력 3
1
예제 입력 4
10 0 1
예제 출력 4
10
예제 입력 5
0 0 1
예제 출력 5
0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, c;
    cin >> X >> Y >> c;

    long long s = (long long)X * X + (long long)Y * Y;

    if (s == 0) {
        cout << 0 << "\n";
    } else if (s == (long long)c * c) {
        cout << 1 << "\n";
    } else if (s < (long long)c * c) {
        cout << 2 << "\n";
    } else {
        double d = sqrt((double)s);
        double k_double = ceil(d / c);
        int k = (int)k_double;
        cout << k << "\n";
    }

    return 0;
}