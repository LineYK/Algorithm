/*
베라의 패션 
 
시간 제한	메모리 제한
2 초	256 MB

문제
베라는 상의 N 벌과 하의 N 벌이 있다. i 번째 상의와 i 번째 하의는 모두 색상 i를 가진다. 
N 개의 색상은 모두 서로 다르다.

상의와 하의가 서로 다른 색상인 조합은 총 몇 가지일까?

입력
입력은 아래와 같이 주어진다.

N
출력
상의와 하의가 서로 다른 색상인 조합의 가짓수를 출력한다.

제한
1 ≤ N ≤ 2017
N은 정수이다.
예제 입력 1 
1
예제 출력 1 
0
예제 입력 2 
2
예제 출력 2 
2
예제 입력 3 
5
예제 출력 3 
20

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    cout << n * (n - 1) << "\n";

    return 0;
}
