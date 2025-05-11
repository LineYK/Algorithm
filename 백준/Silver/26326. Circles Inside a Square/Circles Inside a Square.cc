/*
정사각형 안의 원
 
시간 제한 메모리 제한
1 초 1024 MB

문제
크기가 같은 원 8개가 있고 이를 정사각형 안에 넣고 싶습니다. 사각형의 크기를 최소화하고 싶습니다. 다음 그림은 정사각형 안에 8개의 원을 포장하는 최소한의 방법을 보여줍니다:

반지름 r이 주어졌을 때, 그 반지름의 원 8개가 들어갈 수 있는 최소 정사각형의 면적을 구합니다.

입력
첫 번째 입력 줄에는 테스트 케이스의 수를 나타내는 양의 정수 n이 들어 있습니다. 각 테스트 케이스는 반경 r을 나타내는 한 줄에 양의 실수(0.001에서 1000 사이)로 구성됩니다.

출력
각 테스트 케이스에 대해 반지름 r의 원 8개를 담을 수 있는 최소 사각형의 면적을 출력합니다. 소수점 뒤 5자리를 출력합니다. 판사의 출력과 ±0.00001 이내이면 정답으로 간주합니다.

예제 입력 1 
2
0.1
0.2
예제 출력 1
0.34383
1.37532
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const double A = 2.0 + sqrt(2.0) + sqrt(6.0);
    const double A2 = A * A;
    
    int n;
    cin >> n;
    cout << fixed << setprecision(5);
    while (n--) {
        double r;
        cin >> r;
        double area = A2 * r * r;
        cout << area << "\n";
    }
    return 0;
}
